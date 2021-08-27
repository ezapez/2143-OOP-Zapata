///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Edgar Zapata
// Email:            ezap.ez98@gmail.com
// Label:            A04
// Title:            Linked list Class
// Course:           CMPS 3013
// Semester:         Fall 2021 
//
// Description:
//       The program is using a linked list to be able to push data into it.
//       While using a class we are creating a member varables to be able to que 
//       the linked list. With data that is being push into the class from the main.
//       User are able to add or remove data from this linked list as if its a array function.
//       Though the list is only allocated for 10 spaces due to the dynamic allocation.
//              
// Usage:
//       - $ ./main  main.cpp
//       - This is the main cpp file being used to run the program
//
// Files:
//      main.cpp : Driver program
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *        The class is being used to setup the linked list to be able to 
 *        que 10 elements dynmically. The container method is being set with 
 *        the size of the linkedlist. While rear is going to be pushing in new 
 *        data the user would like. The front will be the one to pop out any data
 *        needing to be removed.
 *     
 *
 * 
 * 
 * Public Methods:
 *     Constructor CircularArrayQue()
 *     Constructor CircularArrayQue(int size)
 *     void        Push(int item)
 *     int         Pop()
 *     friend      &operator<<(ostream &os, const CircularArrayQue &other)  
 * Private Methods:
 *      int     *Container
 *      int      Front;
 *      int      Rear;
 *      int      QueSize;
 *      int      CurrentSize; 
 *      void     init(int size)
 *      bool     full()
 * Usage: 
 * 
 *      - every thing will be done in the main.
 *      
 */

 

 /**
 * Public/Private/Protected :init
 * 
 * Description:
 *      To show how the current size of the linked list
 * 
 * Params:
 *      int*       :Container
 *      int        :Front
 *      int        :Rear
 *      int        :Quesize
 * 
 * Returns:
 *      Size       :returns the size of the linked list 
 */

 /**
 * Public/Private/Protected :Full
 * 
 * Description:
 *      Shows if the linkedlist is full 
 * 
 * Params:
 *      int       :CurrentSize
 *      int       :Quesize
 * 
 * Returns:
 *      full       :shows if the link list is full 
 */

 /**
 * Public/Private/Protected :push
 * 
 * Description:
 *      Push new data into the linkedlist
 * 
 * Params:
 *      int*       :Container
 *      int        :Front
 *      int        :Rear
 *      
 * 
 * Returns:
 *      Adds:     Adds data to the linked list
 */


/**
 * Public/Private/Protected :pop
 * 
 * Description:
 *      removes the data from the front 
 * 
 * Params:
 *      int*       :Container
 *      int        :Front
 *      int        :temp
 *      int        :Quesize
 * Returns:
 *      removes:     removes numbers from linkedlist
 */




class CircularArrayQue {
private:
    int *Container;// dynamic allocares the size of the linked list 
    int Front;// will pop out the data from the front 
    int Rear; // will push data from the back 
    int QueSize; // items in the queue
    int CurrentSize;// shows what the current size of the linked list 
    void init(int size = 0) {// size set to zero
        Front = Rear = CurrentSize = 0;// sets member var to zero
        QueSize = size; // sets the size 
    }

    bool Full() {
        return CurrentSize == QueSize;              // returns size to quesize
    }

public:
    CircularArrayQue() {                         // sets the container size to 10 elements
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {               // sends it to size 
        Container = new int[size];
        init(size);
    }

    void Push(int item) {                    // Adds new data into the linked list untill full
        if (!Full()) {                      // if statement to keep track of size
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {                            // if full the cout will appear 
            cout << "FULL!!!!" << endl;
        }
    }

    int Pop() {                            // removes data from the linked list 
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;    // uses front to take out the first number in the list 
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " "; // for loop to control linked list
    }
    os << endl;
    return os; 
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);
    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);             // push 1 adds to list 
    C1.Push(2);             //push 2 adds to list 
    C1.Push(3);             // push 3 adds to list
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
