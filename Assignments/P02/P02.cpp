/*****************************************************************************
*                    
*  Author:           Edgar Zapata
*  Email:            ezap.ez98@gmail.com
*  Label:            Myvector_class2
*  Title:            vec class
*  Course:           2143-OOP
*  Semester:         Fall 2021
* 
*  Description:
*        Program is using P01 code to be used to overload operators +, -, /, *, <<, =, ==
*        Each  operator will be used in differnet ways to modifiy the values set in the vector list
*        The program will be adding methods to the class to used these operators in main.
*        This will allow the vector to use the overload operator 
* 
*  Usage:
*        just run in a folder 
* 
*  Files:
*       P02.cpp    :driver file
*****************************************************************************/



#include <fstream>
#include <iostream>
#include <string>

using namespace std;


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
 *      - node* next
 *      - node* prev
 * 
 * Private Methods:
 *      none
 * Usage: 
 * 
 *      myvector class is being used to create the functions of a vector
 *      It will be created by using private methods that will be used to operate 
 *      the linked list 
 *      
 */
             
struct node
{
    int data;                                                           // data value (could be a lot more values)

    node *next;                                                         // we always need a "link" in a linked list
    node *prev;

    node(int x)
    {                                                                   // cunstructor to make adding values easy\

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
 *      friend ostream &operator<<(ostream &output, const myVector &otherList)
 *      friend fstream &operator<<(fstream &output, const myVector &otherList)
 *      int &operator[](const int index)
 *      myVector operator=(const myVector &other)
 *      bool operator==(const myVector &other)
 *      myVector operator+(const myVector &other)
 *      myVector operator-(const myVector &other)
 *      myVector operator/(const myVector &other)
 *      myVector operator*(const myVector &other)
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
    node *head;                                                         //node to head
    node *tail;                                                         //node to tail
    int update_Size;                                                    //size keeps updating

public:
    myVector()
    {                                                                   // Default constructor
        head = nullptr;
        tail = nullptr;
        update_Size = 0;
    }

    myVector(int *A, int size)                                          // myVector set to array
    {
        head = nullptr;                                                 // sets head to nullptr
        tail = nullptr;                                                 // sets tail to nullptr
        update_Size = 0;                                                // Size to new size
        for (int i = 0; i < size; i++)
        {
            pushRear(A[i]);                                             // makes the array
        }
    }

    myVector(string filename)
    {
        head = nullptr;                                                 // sets head to nullptr
        tail = nullptr;                                                 // sets tail to nullptr
        update_Size = 0;                                                // Size to new size
        int x = 0;                                                      // x is set to zero to read data in file
        ifstream file_in;
        file_in.open(filename);                                         // opens file name

        while (!file_in.eof())
        {
            file_in >> x;                                               // file data place into x
            pushRear(x);                                                // pushes data to front
            update_Size++;                                              //update size
        }
    }

    void pushFront(int x)
    {
        if (head == nullptr)                                            // head is empty
        {
            head = new node(x);                                         // add new node to list
            tail = head;                                                // set head and tail equal
            update_Size++;                                              //update size
        }

        else
        {
            node *nodeptr = head;                                       // nodeptr to head
            head = new node(x);                                         // set new value to head

            head->next = nodeptr;
            nodeptr->prev = tail;

            update_Size++;
        }
    }

    void pushRear(int x)
    {
        if (tail == nullptr)
        {                                                               // if the tail is empty add the new node
            tail = new node(x);                                         // new node for list
            head = tail;                                                // sets head and tail to one node
            update_Size++;                                              //update size
        }

        else
        {
            node *nodeptr = tail;                                       // set nodeptr to head of list
            tail = new node(x);                                         // set tail to new node
            while (nodeptr->next != nullptr)                            // list not empty traverse the list
            {
                nodeptr = nodeptr->next;                                // move to next node
            }
            nodeptr->next = tail;                                       // setting new node to rear
            update_Size++;                                              // update_Size
        }
    }

    int popFront()
    {
        if (head == nullptr)                                            // if list is empty
        {
            return 0;                                                   // do not return noting
        }
        else
        {
            int x = head->data;                                         // sets first node to be deleted
            node *nodeptr = head;                                       // set nodeptr to head
            head = head->next;                                          // connects back the list
            delete nodeptr;                                             // deletes front node
            update_Size--;                                              // update_Size
            return x;                                                   // returns node being deleted
        }
        return 0;
    }

    int popRear()
    {
        if (tail == nullptr)                                            // is list is empty return noting
        {
            return 0;
        }
        else
        {
            int x = tail->data;                                         // getting data to be pop
            node *nodeptr = head;                                       // nodeptr to head to
            while (nodeptr->next != tail)                               // traverse the list
            {
                nodeptr = nodeptr->next;                                // moves to next node
            }
            tail = nodeptr;                                             //  tail gets set to last node
            tail->next = nullptr;                                       // tail set last node to nullptr
            update_Size--;
            return x;                                                   // updates size
        }
        return 0;
    }

    void pushAt(int x, int loc)
    {
        if (loc < 0 || loc > update_Size)                               // empty list return noting
        {
            return;
        }

        if (loc == 0)                                                   // location first node call pushFront
        {
            pushFront(x);
            update_Size++;
        }
        else if (loc == update_Size)                                    // location last node call pushRear
        {
            pushRear(x);
            update_Size++;
        }
        else
        {
            int count_size = 0;
            node *nodeptr = head;
            node *prevptr = nullptr;

            while (nodeptr != nullptr && count_size != loc - 1)         //traverse the list then goes before the node being delete
            {
                nodeptr = nodeptr->next;
                count_size++;
            }

            prevptr = nodeptr;                                          // set the node being deleted to prevptr to be deleted
            nodeptr = new node(x);                                      //  makes nodeptr new value
            nodeptr->next = prevptr->next;                              //  links the prev node to the node after
            prevptr->next = nodeptr;                                    // links the node back
            update_Size++;
        }
    }

    int popAt(int loc)
    {
        int track = 0;                                                  // returns whats been pop
        if (loc < 0 || loc > update_Size)                               // empty list  return noting
        {
            return 0;
        }
        if (loc == 0)                                                   // location is first node call popfront
        {
            track = popFront();
            update_Size--;
            return track;
        }
        else if (loc == update_Size)                                    //  location is last node call poprear
        {
            track = popRear();
            update_Size--;
            return track;
        }
        else
        {

            int count_size = 0;                                         // counts the size of
            node *nodeptr = head;                                       // nodeptr is set to head to traverse the node
            node *prevptr = nullptr;                                    // temp node to be delete for location need to be pop

            while (nodeptr != nullptr && count_size != loc - 1)         //traverse the list then goes before the node being delete
            {
                nodeptr = nodeptr->next;
                count_size++;
            }
            prevptr = nodeptr->next;                                    // set the node being deleted to prevptr to be deleted
            track = prevptr->data;                                      // tracks the node being deleted
            nodeptr->next = prevptr->next;                              //  links the prev node to the node after
            prevptr->next = nullptr;                                    // set the node being delete to null
            delete prevptr;                                             // deletes node
            update_Size--;
            return track;
        }
        return 0;
    }

    int find(int x)
    {

        if (!head)
        {
            return 0;
        }                                                               // if the list is empty
        if (head->data == x)                                            // if first node in the list return the fist index
        {
            return 0;
        }
        else
        {
            int count_element = 0;                                      //counts the index of element
            node *nodeptr = head;
            while (nodeptr != nullptr && nodeptr->data != x)            // traverse the list
            {
                nodeptr = nodeptr->next;
                count_element++;
            }
            if (!nodeptr)                                               // if  data not in linked list return -1
            {
                return -1;
            }
            return count_element;                                       // returns where the element is located
        }
        return 0;
    }

    void pushRear(myVector &v1)
    {
        node *nodeptr = v1.head;                                        //  gets head of vector 1

        while (nodeptr != nullptr)                                      // traverse the  list
        {
            pushRear(nodeptr->data);                                    //  calls push rear place data to be place in the rear
            nodeptr = nodeptr->next;                                    // links  both list
            update_Size++;
        }
    }

    void pushFront(myVector &v1)
    {
        node *nodeptr = v1.head;
        int *A = new int[v1.update_Size];

        int i = 0;

        while (nodeptr != nullptr)                                      // traverse the  list
        {
            // pushFront(nodeptr ->  data);                             //  calls push rear place data to be place in the rear
            A[i] = nodeptr->data;
            nodeptr = nodeptr->next;                                    // links  both list

            i++;
        }
        for (int i = v1.update_Size - 1; i >= 0; i--)
        {
            pushFront(A[i]);
            update_Size++;
        }
    }

    void print()
    {
        node *temp = head;                                              // temp pointer copies head

        while (temp)
        {                                                               // this loops until temp is NULL
                                                                        // same as `while(temp != NULL)`
            cout << temp->data;                                         // print data from node
            if (temp->next)
            {
                cout << "->";
            }
            temp = temp->next;                                          // move to next node
        }
        cout << endl;
    }

    void printf(ofstream &out)
    {
        node *temp = head;                                              // temp pointer copies head

        while (temp)
        {                                                               // this loops until temp is NULL
                                                                        // same as `while(temp != NULL)`
            out << temp->data;                                          // print data from node
            if (temp->next)
            {
                out << "->";
            }
            temp = temp->next;                                          // move to next node
        }
        out << endl;
    }
    /**
     * Public : ostream &operator << 
     * 
     * Description:
     *      Overload the << opreator to cout values
     * 
     * Params:
     *      ostream & output    : giving a cout a name to output
     *      Myvector &otherlist : calls right side
     * Returns:
     *      The output 
     */
    friend ostream &operator<<(ostream &output, const myVector &otherList)
    {
        node *temp = otherList.head;                                    // makes the rhs to temp
        output << "[";                                                  // to cout [10]
        while (temp)                                                    // traverse the data in list & output
        {
                                                                        // if( temp ->next != nullptr)
            output << temp->data << ',';
            temp = temp->next;
        }
        output << "]";
        output << endl;
        return output;                                                  // returns output 
    }
    /**
     * Public : fstream &operator << 
     * 
     * Description:
     *      Overload the << opreator to outfile
     * 
     * Params:
     *      ostream & output    : giving a cout a name to outfile
     *      Myvector &otherlist : calls right side
     * Returns:
     *      The output 
     */
    friend fstream &operator<<(fstream &output, const myVector &otherList)
    {
        node *temp = otherList.head;                                    // makes rhs to temp
        output << "[";                                                  // to outfile [10]
        while (temp)                                                    // traverse the data in list & outfile
        {
            output << temp->data << ',';
            temp = temp->next;
        }
        output << "]";
        output << endl;
        return output;                                                  // returns output =
    }
    /**
     * Public : int &operator[] 
     * 
     * Description:
     *      Overload the [] to place new data into vector list
     * 
     * Params:
     *      const int index  : for where the new data needs to be places
     * Returns:
     *      returns the data 
     */
    int &operator[](const int index)
    {
        node *find = head;                                              //  sets find to list
                                                                        //node *prevptr = nullptr;   

                                                                        //int track = 0;
        for (int count_size = 0; count_size != index; count_size++)     //  gets the size of the list while it traversaes the list 
        {
            find = find->next;                  
        }
        return find->data;                                              // returns the data in list 
    }
    /**
     * Public : myVector &operator =
     * 
     * Description:
     *      Overload the = to assign values into vector 
     * 
     * Params:
     *      const myVector &other : calls rhs 
     * Returns:
     *      new values to the list  
     */
    myVector operator=(const myVector &other)
    {
        if (this == &other)                                             //self assignment if same object
        {
            return *this;                                               // true skip  assignment, and  return  *this
        }

                                                                        //  this is destroying  this
        node *temp = this->head;
        node *destroy = nullptr;                                        // node to be deleted

        while (temp != nullptr)                                         // traverse the list 
        {
            destroy = temp;                                             // sets the nodes to be deleted 
            temp = temp->next;
            delete destroy;                                             // deletes the nodes 
        }
        head = nullptr;                                                 // reset the head,tail,and size for list  
        tail = nullptr;
        update_Size = 0;
        node *rhs = other.head;

        while (rhs != nullptr)                                          // traverse the rhs list
        {
            this->pushRear(rhs->data);                                  // pushs the values to to the rear 
            rhs = rhs->next;                
        }

        return *this;
    }
    /**
     * Public : bool operator==
     * 
     * Description:
     *      Overload the == to compare values
     * 
     * Params:
     *      Myvector &otherlist : calls right side
     * Returns:
     *      0 or 1 for they are similar 
     */
    bool operator==(const myVector &other)
    {
        node *temp = other.head;                                        // set rhs to tmep 

        int size = 0;                                                   // size for first list
        int size_2 = 0;                                                 // size for second list

        while (temp != nullptr)                                         // while loop to traverse the list and to find the size of the first list 
        {
            temp = temp->next;
            size++;
        }
        while (head != nullptr)                                         // while loop to traverse the list and to find the size of the second list 
        
        {
            head = head->next;
            size_2++;
        }

        if (size == size_2)                                             // compare the list size if true return true , else return false
        {
            return true;
        }
        else
        {
            return false;
        }

        return -1;                                                      // makes sure its not returning  anything
    }
    /**
     * Public : myVector operator+
     * 
     * Description:
     *      Overload the + to add values
     * 
     * Params:
     *      Myvector &otherlist : calls right side
     * Returns:
     *      new list 
     */

    myVector operator+(const myVector &other)
    {
        myVector temp;                                                  // make a temp vector
        node *list1 = head;                                             // list1 to head
        node *other_list2 = other.head;                                 // other list to other_list2

        while (list1 != nullptr && other_list2 != nullptr)              // traverse each list 
        {       
            temp.pushRear(list1->data + other_list2->data);             // add each list to each other and push the values not add to the rear
            list1 = list1->next;
            other_list2 = list1->next;
        }

        while (list1 != nullptr)                                        // traveres list 1
        {
            temp.pushRear(list1->data);                                 // pushrear the data of list one 
            list1 = list1->next;
        }

        while (other_list2 != nullptr)                                  // traverse list 2
        {
            temp.pushRear(other_list2->data);                           // push rear the data of list two
            other_list2 = other_list2->next;
        }

        return temp;                                                    // return new list 
    }
    
    /**
     * Public : myVector operator-
     * 
     * Description:
     *      Overload the - to subtract values
     * 
     * Params:
     *      Myvector &otherlist : calls right side
     * Returns:
     *      new list 
     */
    myVector operator-(const myVector &other)
    {
        myVector temp;

        node *list1 = head;
        node *other_list2 = other.head;

        while (list1 != nullptr && other_list2 != nullptr)
        {
            temp.pushRear(list1->data - other_list2->data);
            list1 = list1->next;
            other_list2 = list1->next;
        }

        while (list1 != nullptr)
        {
            temp.pushRear(list1->data);
            list1 = list1->next;
        }

        while (other_list2 != nullptr)
        {
            temp.pushRear(other_list2->data);
            other_list2 = other_list2->next;
        }

        return temp;
    }
    /**
     * Public : myVector operator/
     * 
     * Description:
     *      Overload the / to divide values
     * 
     * Params:
     *      Myvector &otherlist : calls right side
     * Returns:
     *      new list 
     */
    myVector operator/(const myVector &other)
    {
        myVector temp;

        node *list1 = head;
        node *other_list2 = other.head;

        while (list1 != nullptr && other_list2 != nullptr)
        {
            temp.pushRear(list1->data / other_list2->data);
            list1 = list1->next;
            other_list2 = list1->next;
        }

        while (list1 != nullptr)
        {
            temp.pushRear(list1->data);
            list1 = list1->next;
        }

        while (other_list2 != nullptr)
        {
            temp.pushRear(other_list2->data);
            other_list2 = other_list2->next;
        }

        return temp;
    }
    /**
     * Public : myVector operator*
     * 
     * Description:
     *      Overload the * to  multiply values
     * 
     * Params:
     *      Myvector &otherlist : calls right side
     * Returns:
     *      new list 
     */
    myVector operator*(const myVector &other)
    {
        myVector temp;

        node *list1 = head;
        node *other_list2 = other.head;

        while (list1 != nullptr && other_list2 != nullptr)
        {
            temp.pushRear(list1->data * other_list2->data);
            list1 = list1->next;
            other_list2 = other_list2->next;
        }

        while (list1 != nullptr)
        {
            temp.pushRear(list1->data);
            list1 = list1->next;
        }

        while (other_list2 != nullptr)
        {
            temp.pushRear(other_list2->data);
            other_list2 = other_list2->next;
        }

        return temp;
    }
};

int main()
{

    int a1[] = {1, 2, 3, 4, 5};
    int a2[] = {10, 20, 30};

    myVector v1(a1, 5);
    myVector v2(a2, 3);

    ofstream fout;
    fout.open("output.txt");

    cout << v1[2] << endl;
    //writes out 3

    v1[4] = 9;
    //v1 now = [1,2,3,4,9]

    cout << v1 << endl;
    //writes out [1,2,3,4,9]` to console.

    fout << v1 << endl;
    // writes out [1,2,3,4,9]` to your output file.

    myVector v3 = v1 + v2;
    cout << v3 << endl;
    //writes out [11,22,33,4,9]` to console.

    v3 = v1 - v2;
    cout << v3 << endl;
    // writes out [-9,-18,-27,4,9]` to console.

    v3 = v2 - v1;
    cout << v3 << endl;
    // writes out [9,18,27,4,9]` to console.

    v3 = v2 * v1;
    cout << v3 << endl;
    // writes out [10,40,90,4,9]` to console.

    v3 = v1 * v2;
    cout << v3 << endl;
    // writes out [10,40,90,4,9]` to console.

    v3 = v1 / v2;
    cout << v3 << endl;
    // writes out [0,0,0,4,9]` to console.

    v3 = v2 / v1;
    cout << v3 << endl;
    // writes out [10,10,10,4,9]` to console.

    cout << (v2 == v1) << endl;
    // writes 0 to console (false) .

    myVector v4 = v1;
    cout << (v4 == v1) << endl;
    // writes 1 to console (true) .

    return 0;
}