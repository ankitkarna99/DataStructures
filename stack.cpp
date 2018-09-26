#include <iostream>
#include "singlyLinkedList.hpp"

using namespace std;

template <class T>
class Stack {
    private:
        LinkedList<T> list;
    public:
        void push(T data){
            list.addFront(data);
        }
        T pop(){
            T temp = list.getFront();
            list.removeFront();
            return temp;
        }
        T peek(){
            return list.getFront();
        }
        int stackSize() {
            return list.getSize();
        }
        void printStack(){
            cout << "Printing stack from top to bottom:" << endl;
            list.printList();
        }
        bool isEmpty(){
            return (list.getSize() == 0) ? true : false;
        }
};

int main(){
    Stack<int> intStack;
    cout << "Empty: " << intStack.isEmpty() << endl;
    intStack.push(5);
    intStack.push(6);
    intStack.push(7);
    intStack.push(8);
    cout << "Empty: " << intStack.isEmpty() << endl;
    intStack.printStack();
    cout << "Popped: " << intStack.pop() << endl;
    cout << "Peeking: " << intStack.peek() << endl;
    cout << "Stack Size: " << intStack.stackSize() << endl;
    return 0;
}