#include <iostream>
#include "singlyLinkedList.hpp"

using namespace std;

template <class T>
class Queue {
    private:
        LinkedList<T> list;
    public:
        void enqueue(T data){
            list.addBack(data);
        }
        T dequeue(){
            T temp = list.getFront();
            list.removeFront();
            return temp;
        }
        T front(){
            return list.getFront();
        }
        T rear(){
            return list.getBack();
        }
        int queueSize() {
            return list.getSize();
        }
        void printQueue(){
            cout << "Printing queue from first to last:" << endl;
            list.printList();
        }
        bool isEmpty(){
            return (list.getSize() == 0) ? true : false;
        }
};