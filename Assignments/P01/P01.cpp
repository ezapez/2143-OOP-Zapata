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



#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void openfiles(ofstream &outfile)                           //out files the output
{
  outfile.open("test.out");                                 //open out putfile
}
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
             
                                                            //Node for our linked list
struct node
{
  int data;                                                 //data value (could be a lot more values)

  node *next;                                               //we always need a "link" in a linked list
  node *prev;

  node(int x)
  {                                                         //cunstructor to make adding values easy\

    data = x;
    next = NULL;
    prev = NULL;
  }
};

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

class myVector
{
private:
  node *head;                                               //node to head
  node *tail;                                               //node to tail
  int update_Size;                                          //size keeps updating

public:
  myVector()
  {                                                         //Default constructor
    head = nullptr;
    tail = nullptr; 
    update_Size = 0;
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

  myVector(int *A, int size)                                //myVector set to array
  {
    head = nullptr;                                         //sets head to nullptr
    tail = nullptr;                                         //sets tail to nullptr
    update_Size = 0;                                        //Size to new size
    for (int i = 0; i < size; i++)
    {
      pushRear(A[i]);                                       //makes the array
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
  myVector(string filename)
  {
    head = nullptr;                                         // sets head to nullptr
    tail = nullptr;                                         // sets tail to nullptr
    update_Size = 0;                                        // Size to new size
    int x = 0;                                              // x is set to zero to read data in file
    ifstream file_in;
    file_in.open(filename);                                 // opens file name

    while (!file_in.eof())
    {
      file_in >> x;                                         //file data place into x
      pushRear(x);                                          //pushes data to front
      update_Size++;                                        //update size
    }
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
    if (head == nullptr)                                    //head is empty
    {
      head = new node(val);                                 // add new node to list
      tail = head;                                          // set head and tail equal
      update_Size++;                                        //update size
    }

    else
    {
      node *nodeptr = head;                                 // nodeptr to head
      head = new node(val);                                 // set new value to head

      head->next = nodeptr;
      nodeptr->prev = tail;

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
    if (tail == nullptr)
    {                                                       // if the tail is empty add the new node
      tail = new node(val);                                 // new node for list
      head = tail;                                          // sets head and tail to one node
      update_Size++;                                        //update size
    }

    else
    {
      node *nodeptr = tail;                                 // set nodeptr to head of list
      tail = new node(val);                                 // set tail to new node
      while (nodeptr->next != nullptr)                      // list not empty traverse the list
      {
        nodeptr = nodeptr->next;                            // move to next node
      }
      nodeptr->next = tail;                                 // setting new node to rear
      update_Size++;                                        // update_Size
    }
  }
 /**
     * Function int popFront()
     *      push  the node to the back of the list
     *    
     * 
     * Params:
     *      if()
     *        - to make sure no nodes in the list if so return 0
     *      else
     *        -  pops the nodes from the front  
     * Returns
     *      -returns  the val pop 
     */
  int popFront()
  {
    if (head == nullptr)                                    // if list is empty
    {
      return 0;                                             // do not return noting
    }
    else
    {
      int x = head->data;                                   // sets first node to be deleted
      node *nodeptr = head;                                 // set nodeptr to head
      head = head->next;                                    // connects back the list
      delete nodeptr;                                       // deletes front node
      update_Size--;                                        // update_Size
      return x;                                             // returns node being deleted
    }
    return 0;
  }
/**
     * Function int popRear()
     *      pops  the node to the back of the list
     *    
     * 
     * Params:
     *      if()
     *        - to make sure no empty  list returns 0;
     *      else
     *        -  we are going to pop data from the rear
     * Returns:
     *      -returns  node to the rear of  the list 
     */

  int popRear()
  {
    if (tail == nullptr)                                    // is list is empty return noting
    {
      return 0;
    }
    else
    {
      int x = tail->data;                                   // getting data to be pop
      node *nodeptr = head;                                 // nodeptr to head to
      while (nodeptr->next != tail)                         // traverse the list
      {
        nodeptr = nodeptr->next;                            // moves to next node
      }
      tail = nodeptr;                                       //  tail gets set to last node
      tail->next = nullptr;                                 // tail set last node to nullptr
      update_Size--;
      return x;                                             // updates size
    }
    return 0;
  }
 /**
     * Function void pushAt(int loc, int val)
     *      pushing val to the location 
     *    
     * 
     * Params:
     *      if()
     *        - to make sure no nodes in the list
     *        - loc is  0 call  pushfront
     *        - last index call pushrear
     *      else
     *        -  sends a node in while there is nodes already in list  
     * Returns
     *      -returns  node to the rear of  the list 
     */
  void pushAt(int val, int loc)
  {
    if (loc < 0 || loc > update_Size)                       // empty list return noting
    {
      return;
    }

    if (loc == 0)                                           // location first node call pushFront
    {
      pushFront(val);
      update_Size++;
    }
    else if (loc == update_Size)                            // location last node call pushRear
    {
      pushRear(val);
      update_Size++;
    }
    else
    {
      int count_size = 0;
      node *nodeptr = head;
      node *prevptr = nullptr;

      while (nodeptr != nullptr && count_size != loc - 1)   //traverse the list then goes before the node being delete
      {
        nodeptr = nodeptr->next;
        count_size++;
      }

      prevptr = nodeptr;                                    //set the node being deleted to prevptr to be deleted
      nodeptr = new node(val);                              //makes nodeptr new value
      nodeptr->next = prevptr->next;                        //links the prev node to the node after
      prevptr->next = nodeptr;                              //links the node back
      update_Size++;
    }
  }
 /**
  * Function int popAt(int  loc)
  *      pops at a location on the linkedlist
  * 
  * Params:
  *      if()
  *        - to make sure no nodes in the list
  *        - if location zero call push front
  *        - if location last index call push rear
  *      else
  *        -  traverse the list to find the  location need to be popped 
  * Returns
  *      -returns  node being pop by location
  */

  int popAt(int loc)
  {
    int track = 0;                                          // returns whats been pop
    if (loc < 0 || loc > update_Size)                       // empty list  return noting
    {
      return 0;
    }
    if (loc == 0)                                           // location is first node call popfront
    {
      track = popFront();
      update_Size--;
      return track;
    }
    else if (loc == update_Size)                            //  location is last node call poprear
    {
      track = popRear();
      update_Size--;
      return track;
    }
    else
    {

      int count_size = 0;                                   // counts the size of
      node *nodeptr = head;                                 // nodeptr is set to head to traverse the node
      node *prevptr = nullptr;                              // temp node to be delete for location need to be pop

      while (nodeptr != nullptr && count_size != loc - 1)   //traverse the list then goes before the node being delete
      {
        nodeptr = nodeptr->next;
        count_size++;
      }
      prevptr = nodeptr->next;                              // set the node being deleted to prevptr to be deleted
      track = prevptr->data;                                // tracks the node being deleted
      nodeptr->next = prevptr->next;                        //  links the prev node to the node after
      prevptr->next = nullptr;                              // set the node being delete to null
      delete prevptr;                                       // deletes node
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

    if (!head)
    {
      return 0;
    }                                                       // if the list is empty
    if (head->data == val)                                  // if first node in the list return the fist index
    {
      return 0;
    }
    else
    {
      int count_element = 0;                                //counts the index of element
      node *nodeptr = head;
      while (nodeptr != nullptr && nodeptr->data != val)    // traverse the list
      {
        nodeptr = nodeptr->next;
        count_element++;
      }
      if (!nodeptr)                                         // if  data not in linked list return -1
      {
        return -1;
      }
      return count_element;                                 // returns where the element is located
    }
    return 0;
  }
 /**
     * Function void pushrear(myVector &v1)
     *      sets vector 2 or any  to link there list at the rear 
     *    
     * 
     * Params:
     *      while(nodePtr!=NULL)
     *        - make sure the nodeptr is not null to run while loop
     * Returns
     *      -returns  vectors nodes to the rear of another vector 
     */
  void pushRear(myVector &v1)
  {
    node *nodeptr = v1.head;                                //  gets head of vector 1

    while (nodeptr != nullptr)                              // traverse the  list
    {
      pushRear(nodeptr->data);                              //  calls push rear place data to be place in the rear
      nodeptr = nodeptr->next;                              // links  both list
      update_Size++;
    }
  }
  /**
     * Function void pushfront(myVector &v1)
     *      adds list from vector 2 to front of vector 1
     *      
     *    
     * 
     * Params:
     *      while
     *        - to set the list to be able to push from the front
     * Returns
     *      -suppose to return to the front 
     */
  void pushFront(myVector &v1)
  {
    node *nodeptr = v1.head;
    int *A = new int[v1.update_Size];                       // set list to array to be reverse 

    int i = 0;        

    while (nodeptr != nullptr)                              // traverse the  list
    {
      A[i] = nodeptr->data;                                 // add the data to list 
      nodeptr = nodeptr->next;                              // links  both list

      i++;
    }
    for (int i = v1.update_Size - 1; i >= 0; i--)          // reverse the list to be push to front 
    {
      pushFront(A[i]);
      update_Size++;
    }
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
  void print()
  {
    cout << "[";                                            // adds  []

    node *nodePtr = head;                                   // new nodePtr
    while (nodePtr)
    {                                                       //node ptr to print out nodes
      cout << nodePtr->data << ",";
      nodePtr = nodePtr->next;
    }
    cout << "]";

    cout << '\n';
  }
   /**
     * Function void  printf(ofstream &const)
     *      prints nodes
     *    
     * 
     * Params:
     *      while
     *        - outfiles the print to .out file 
     * Returns
     *      - outputs the data 
     */
  void printf(ofstream &out)
  {
    node *temp = head;                                      // temp pointer copies head
    out << "[";
    while (temp)
    {                                                       // this loops until temp is NULL
                                                            // same as `while(temp != NULL)`
      out << temp->data;                                    // print data from node
      if (temp->next)
      {
        out << ",";
      }
      temp = temp->next;                                    // move to next node
    }
    out << ']';
    out << endl;
  }
};





int main()
{
  ofstream outfile;
  outfile.open("test.out");
  int x = 0;
  outfile << "Edgar Zapata" << endl;
  outfile << "10/17/2021" << endl;
  outfile << "Fall 2143" << endl;
  outfile << endl
          << endl;
  myVector v1;
  v1.pushFront(18);
  v1.pushFront(20);
  v1.pushFront(25);
  v1.pushRear(18);
  v1.pushRear(20);
  v1.pushRear(25);
  v1.print();
  v1.printf(outfile);
  // [25, 20, 18, 18, 20, 25]

  int A[] = {11, 25, 33, 47, 51};
  myVector v2(A, 5);
  v2.print();
  v2.printf(outfile);
  // [11, 25, 33, 47, 51]

  v2.pushFront(9);
  //v2.inOrderPush(27);
  v2.pushRear(63);
  v2.print();
  v2.printf(outfile);
  // [9, 11, 25, 33, 47, 51, 63]

  v1.pushRear(v2);
  v1.print();
  v1.printf(outfile);
  // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

  x = v1.popFront();
  x = v1.popFront();
  x = v1.popFront();
  v1.print();
  v1.printf(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
  cout << x << endl;
  outfile << x << endl;
  // 18

  x = v1.popRear();
  x = v1.popRear();
  x = v1.popRear();
  v1.print();
  v1.printf(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33]
  cout << x << endl;
  outfile << x << endl;
  // 47

  x = v2.popAt(3);
  v2.print();
  v2.printf(outfile);
  // [9, 11, 25, 33, 47, 51, 63]
  cout << x << endl;
  outfile << x << endl;
  // 27

  x = v2.find(51);
  cout << x << endl;
  outfile << x << endl;
  // 5

  x = v2.find(99);
  cout << x << endl;
  outfile << x << endl;
  // -1

  myVector v3(v1);
  v3.print();
  v3.printf(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33]

  v3.pushFront(v2);
  v3.print();
  v3.printf(outfile);
  //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  myVector v4("input.dat");
  v4.pushRear(v3);
  v4.print();
  v4.printf(outfile);
  // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  return 0;
}