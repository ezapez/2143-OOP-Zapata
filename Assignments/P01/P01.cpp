/*****************************************************************************
*                    
*  Author:           Edgar Zapata
*  Email:            ezap.ez98@gmail.com
*  Label:            Myvector_class
*  Title:            vec class
*  Course:           2143-OOP
*  Semester:         Fall 2021
* 
*  Description:
*        Program is using code from Prof.Griffen example code.
*        The code only has a minmal functionalty. Goal for 
*        program is to add more things to the code.
*        Bascially make act like a vector, but creating it with a
*        linked list. I went ahead and add all the requirments that
*        need to be add to the vecotor class, however in my void pushFront(myVector &v2)
*        I could not seem to figure it with it given me a wrong output when pushing
*        from vector 3. However the rest of the code still works. 
* 
*  Usage:
*        just run in a folder with input.dat
* 
*  Files:
*       main.cpp    :driver file
*       input.dat   :input data
*****************************************************************************/



#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void openfiles(ofstream& outfile)       // out files the output
{
    outfile.open("test.out");          //open out putfile
}
/**
 * Class Name myVector
 * 
 * Description:
 *          myVector is going to add new methods to already existed linked list. 
 *          it will hold methods to make the linked list act as a vector. Theses
 *          methods will help add,remove, locoated, and do many more things.
 *          this is all being done with struct to act as the node creater.To help 
 *          link the nodes together.
 *      
 * 
 * Public Methods:
 *       myVector()
 *              - Default constructor 
 *              - no return 
 *     
 *       myVector(int *A, int size)
 *              - simple constructor
 *              - sets linked list to array
 *       myVector(string fileName) 
 *              - returns the input.dat 
 *       void pushFront(int val)
 *              - returns linked node in the front of list
 *       void pushRear(int val)
 *              - returns linkes node in the back of the list
 *       void pushFront(myVector &v2)
 *              - returns push front to vector 2 
 *       void pushRear(myVector &v2)
 *              - returns push rear to vector 2
 *       int popFront()
 *              - deletes node from the front
 *              - returns delete node
 *       int popRear()
 *              - delete node from the rear
 *              - returns delete node
 *       void pushAt(int loc, int val)
 *              - pushes the new val into new location in list
 *       int popAt(int loc)
 *              - deletes node in any location on linked list
 *              - returns delete node
 *              - returns -1 if not withing the size  of the node
 *       int find(int val)
 *              - returns the index of the val with in the linked list
 *       void print()  
 *             - returns outfile test.out
 *             - prints out the data    
 *      
 * 
 * Private Methods:
 *      node* head
 *      node* tail  
 * 
 * Usage: 
 * 
 *      myvector class is being used to create the functions of a vector
 *      It will be created by using private methods that will be used to operate 
 *      the linked list 
 *      
 */
class myVector{
    private:

/**
 * Class Name node
 * 
 * Description: 
 *          this is class is setup to act as the linked list node connecter
 *          going to link, add, and reverse into nodes for the vector
 *           
 * 
 * Public Methods:
 *      - node(int x)
 *      - returns data 
 *      - returns next 
 *      - returns prev
 * 
 * Private Methods:
 *      node* next
 *      node* prev 
 * 
 * Usage: 
 * 
 *      myvector class is being used to create the functions of a vector
 *      It will be created by using private methods that will be used to operate 
 *      the linked list 
 *      
 */
        struct node {
        int data;                                    // data value (could be a lot more values)
        node* next;                                 // goes to the next node aka links 
        node* prev;                                //  goes to the previous node 

        node(int x)
        {                                         // constructor to make adding values easy
            data = x; 
            next = NULL;                         // sets next to null for no random dumps
            prev = NULL;                        // sets next to null for no random dumps
        }

    };

        node* head;                             // vectors linkedlist  head
        node* tail;                            //  vectors  linkedlist tail
        int update_Size;                      //  to update size of vector


          


    public:

        myVector(){                        //Default constructor 
            head = NULL;                  //set head to null for no fails
            tail = NULL;                 //set head to null for no fails
            update_Size  = 0;
        }
     /**
     * Function myvector(int* A, int size):
     *      sets the linked list into a array for nodes to be placed
     * 
     * Params:
     *      pushRear(A[y])
     *     
     * Returns
     *      -returns  nodes to array 
     */
        myVector(int *A, int size){   // from an array 
            head = NULL;              //set head to null for no fails
            tail = NULL;              //set head to null for no fails
            update_Size = 0;         // setting size of vector
            for(int y =  0; y <  size; y++)
            {
              pushRear(A[y]);     // set the array for  vector
            }
        }
      

      /**
     * Function myvector(string  filename):
     *      reads the data  file into a vector  in the main
     *    
     * 
     * Params:
     *      int x 
     *        - reads  the  data  gets  placed in it
     * 
     *      while(!file_in.eof())
     *        - reads the whole file to the in of file
     *     
     * Returns
     *      -returns  nodes to array 
     */
        myVector(string fileName) {
            head = NULL;
            tail = NULL;
            int x = 0;                   // set x to zero for data to be place
            ifstream file_in;           //  to  read file in as  fin
            file_in.open(fileName);    //  opens file 
            update_Size = 0;          //  sets size to zero 

             while(!file_in.eof()) {  
                      file_in >> x;
                      pushRear(x);  // push data to the rear
                      update_Size++;//  updates  size 
                    }
                    file_in.close(); // closes the  file
    }

   /**
     * Function void pushFront(int  val)
     *      push  the node from the front of the list
     *    
     * 
     * Params:
     *      if()
     *        - to make sure no nodes in the list
     *      else
     *        -   sends a node in while there is nodes already in list
     * Returns
     *      -returns  node to the front of  the list 
     */
        void pushFront(int val)
        {
          if(head == NULL)                          // no nodes add the first one
          {
            head = new node(val);                 // head to new node
            tail = head;                         // sets head to tail when theres a empty list
            update_Size++;                      // updates size of the array 
          }
          else{
            node* nodePtr = head;             // old value to nodePtr
            head = new node(val);            // new value to head
            head -> next = nodePtr;         // head to next to nodePtr
             update_Size++;   
          }

        }
    /**
     * Function void pushrear(int  val)
     *      push  the node to the back of the list
     *    
     * 
     * Params:
     *      if()
     *        - to make sure no nodes in the list
     *      else
     *        -  sends a node in while there is nodes already in list  
     * Returns
     *      -returns  node to the rear of  the list 
     */
        void pushRear(int val)
        {
          if(tail == NULL)
          {
            tail = new node(val);
            head = tail;
            update_Size++;
          }
          else 
          {
              tail = new node(val);                   //set tail to new value
              node* nodePtr = head;                 // puts head to nodeptr to start from the front of the list 
              while(nodePtr -> next != NULL)      //traverse the link list 
              {
                nodePtr = nodePtr -> next;      // point the next to the last node  
              }
            nodePtr -> next = tail;         // set the new value at the rear
          }
          update_Size++;                   // updates size
        }
        
    /**
     * Function void pushfront(int  val)
     *      push  the node to the back of the list
     *    
     * 
     * Params:
     *      if()
     *        - to make sure no nodes in the list
     *      else
     *        -  sends a node in while there is nodes already in list  
     * Returns
     *      -returns  node to the rear of  the list 
     */


         void pushFront(myVector &v2)
        {
          node* nodePtr = v2.tail;
           while(nodePtr)
          {
            pushRear(nodePtr -> data);
            nodePtr = nodePtr -> prev;
          }

          
        }
     /**
     * Function void pushrear(int  val)
     *      push  the node to the back of the list
     *    
     * 
     * Params:
     *      if()
     *        - to make sure no nodes in the list
     *      else
     *        -  sends a node in while there is nodes already in list  
     * Returns
     *      -returns  node to the rear of  the list 
     */
        void pushRear(myVector &v2)
        {
          node* nodePtr = v2.head;
          while(nodePtr!=NULL)
          {
            pushRear(nodePtr -> data);
            nodePtr = nodePtr ->next;
            update_Size++;
          }

        }
        
    /**
     * Function void pushrear(int  val)
     *      push  the node to the back of the list
     *    
     * 
     * Params:
     *      if()
     *        - to make sure no nodes in the list
     *      else
     *        -  sends a node in while there is nodes already in list  
     * Returns
     *      -returns  node to the rear of  the list 
     */
        int popFront()
        {
          if(head == NULL) // if there is noting in the list return 0 
          {
            return 0;
          }
          else{
              int val = head -> data;  
              node* nodePtr = head;
              head = head -> next;
              head -> prev = NULL;
              delete nodePtr;
              update_Size--;
              return val;
          }
          return 0;
        }

    /**
     * Function void pushrear(int  val)
     *      push  the node to the back of the list
     *    
     * 
     * Params:
     *      if()
     *        - to make sure no nodes in the list
     *      else
     *        -  sends a node in while there is nodes already in list  
     * Returns
     *      -returns  node to the rear of  the list 
     */

        int popRear()
        {
          if(tail == NULL)
          {
            return 0;
          }
          else{
            int val = tail -> data;
            node* nodePtr = head;
            
            while(nodePtr -> next != tail) //traverse the link list 
              {
                nodePtr = nodePtr -> next;  // point the next to the last node  
              }

            tail = nodePtr;       // tail to equal to nullptr 
            nodePtr = nodePtr -> next;
            delete nodePtr;
            tail -> next = NULL;
            update_Size--;
            return val;
          }
          return 0;
        }
      /**
     * Function void pushrear(int  val)
     *      push  the node to the back of the list
     *    
     * 
     * Params:
     *      if()
     *        - to make sure no nodes in the list
     *      else
     *        -  sends a node in while there is nodes already in list  
     * Returns
     *      -returns  node to the rear of  the list 
     */

        void pushAt(int loc, int val){
              if(loc < 0 ||loc > update_Size ){return;} // return noting 
              if(loc == 0)
              {
                pushFront(val);
                update_Size++;
              }
              else if(loc == update_Size)
              {
                      pushRear(val);
                      update_Size++;
              }
              else{
                int count_size = 0;

                node* nodePtr = head;
                node* prevnodePtr = nodePtr -> prev;

                while(nodePtr != NULL && count_size != loc-1) //traverse the link list 
                {
                  nodePtr = nodePtr -> next;  //   
                  count_size++;
                }

                prevnodePtr = nodePtr;
                nodePtr = new node(val);
                nodePtr->next =  prevnodePtr -> next;
                prevnodePtr -> next = nodePtr;
                update_Size++;

              }

        }

        /**
     * Function void pushrear(int  val)
     *      push  the node to the back of the list
     *    
     * 
     * Params:
     *      if()
     *        - to make sure no nodes in the list
     *      else
     *        -  sends a node in while there is nodes already in list  
     * Returns
     *      -returns  node to the rear of  the list 
     */

        int popAt(int loc){
                 if(loc < 0 ||loc >= update_Size ){return 0;} // return noting 
              if(loc == 0)
              {
                popFront();
                update_Size++;
              }
              else if(loc == update_Size)
              {
                      popRear();
                      update_Size++;
              }
              else{
                int count_size = 0;

                node* nodePtr = head;
                node* temp = nullptr; 

                while(nodePtr != NULL && count_size != loc-1) //traverse the link list 
                {
                  nodePtr = nodePtr -> next;  //   
                  count_size++;
                }
                int track = 0;  // keeps track of where the node being deleted is 
                temp = nodePtr -> next;
                track = temp -> data;
                nodePtr -> next = temp-> next;
                temp -> next = NULL; 
                delete temp;
                update_Size--;
                return track; 

              }
              return 0;
        }


        /**
     * Function find(int val)
     *      finds where the index the number is with in the list
     *    
     * 
     * Params:
     *      int count_Element = 0;
     *        - count to traverse the linked list
     *      if()
     *        - to see if its the first node
     *      else
     *        -  is  to find the node with in the list  
     * Returns
     *      -returns  node to the rear of  the list 
     */


          int find(int val)
          {
            int count_Element = 0;
            
            if(head -> data == val)                               // if the first node 
            {
              return 0;                                        // returns index zero
            }
            else{
               node* nodePtr = head;                          // new nodePtr
               while(nodePtr!= NULL && nodePtr->data != val) // making sure the data is in the linked lits
               {
                 nodePtr = nodePtr -> next;                 // traverse the list
                  count_Element++;                         // counts where its in the list  untill it finds value
               }  

               return count_Element++;                   // returns  the index of data 
            }
            return 0;
          }

        

    /**
     * Function void  print()
     *      prints nodes
     *    
     * 
     * Params:
     *      while
     *        - prints the nodes from nodePtr
     * Returns
     *      - outputs the data 
     */

        void print() { 
          ofstream outfile;             // outfile 
          openfiles(outfile);           //  calls void for out file
          outfile << "Edgar Zapata" << endl;
          outfile << "10/9/2021"  <<  endl;
          outfile << "Fall 2143" <<  endl;
          outfile << endl;

          cout << "[";              // adds  []
          outfile << '[';
            node* nodePtr = head;   // new nodePtr
            while (nodePtr){        //node ptr to print out nodes
                cout << nodePtr ->data << ",";
                outfile << nodePtr ->data << ","; 
                nodePtr = nodePtr->next;
                
            }
                cout << "]";
                outfile << ']';
            cout << '\n';
            outfile << endl;

        }

        

};







    

int main() {
   

    cout << "Edgar Zapata" << endl;
    cout << "10/9/2021"  <<  endl;
    cout << "Fall 2143" <<  endl;
    cout << endl; 
    

int x = 0;

myVector v1;
v1.pushFront(18);
v1.pushFront(20);
v1.pushFront(25);
v1.pushRear(18);
v1.pushRear(20);
v1.pushRear(25);
v1.print();

// [25, 20, 18, 18, 20, 25]

int A[] = {11,25,33,47,51};
myVector v2(A,5);
v2.print();
// [11, 25, 33, 47, 51]

v2.pushFront(9);
//v2.inOrderPush(27);
v2.pushRear(63);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]

v1.pushRear(v2);
v1.print();
// [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

x = v1.popFront();
x = v1.popFront();
x = v1.popFront();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
cout<<x<<endl;
// 18

x = v1.popRear();
x = v1.popRear();
x = v1.popRear();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33]
cout<<x<<endl;
// 47

x = v2.popAt(3);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]
cout<<x<<endl;
// 27

x = v2.find(51);
cout<<x<<endl;
// 5

x = v2.find(99);
cout<<x<<endl;
// -1

myVector v3(v1);
v3.print();
// [18, 20, 25, 9, 11, 25, 27, 33]

v3.pushFront(v2);
v3.print();
//[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

myVector v4("input.dat");
v4.pushRear(v3);
v4.print();
// [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

return 0;
}
