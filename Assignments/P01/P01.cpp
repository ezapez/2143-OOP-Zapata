
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Node for our linked list
struct node {
    int data;  // data value (could be a lot more values)

    node* next;  // we always need a "link" in a linked list
    

    
    node(int x) {  // cunstructor to make adding values easy
        data = x;
        next = NULL;
    }
};



class myVector{
    private:
        node* head;
        node* tail;



    public:

        myVector(int *A, int  size){   // from an array 

        }

        myVector(string FileName){      // from a file
            ifstream fin;
            fin.open("filename"); 

            while(!fin.eof()){
                fin 
            }

        }



        new myVector(myVector V1){

        }
        



//     void printArr(int* arr, int size) {
//         for (int i = 0; i < size; i++) {
//         cout << "[" << arr[i] << "]";
//     }
//         cout << "\n";
// }


}







    void Push(int x) {
        node* tempPtr = new node(x);  // create a new node and
                                      // add data to it

        if (!head) {  // `!head` implies empty list
                      // So does `head == NULL`

            head = tempPtr;  // `head = tempPtr` places addrress of
                             // tempPtr in head (points head to tempPtr)

        } else {                   // list not empty
            tempPtr->next = head;  // point tempPtr's next to what head points to
            head = tempPtr;        // now point head to tempPtr
        }
    }

    void print() {
        node* temp = head;  // temp pointer copies head

        while (temp) {  // this loops until temp is NULL
                        // same as `while(temp != NULL)`

            cout << temp->data;  // print data from node
            if (temp->next) {
                cout << "->";
            }
            temp = temp->next;  // move to next node
        }
        cout << endl;
    }

    ~LinkedList() {
    }
};

int main() {
    cout << "Edgar Zapata" << endl;
    cout << "10/9/2021"  <<  endl;
    cout << "Fall 2143" <<  endl;

    int x = 0;

    // MyVector v1;
    // v1.pushFront(18);
    // v1.pushFront(20);
    // v1.pushFront(25);
    // v1.pushRear(18);
    // v1.pushRear(20);
    // v1.pushRear(25);
    // v1.print();

    

    return 0;
}