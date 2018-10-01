#include <iostream>

using namespace std;

template <class T>
class Queue {
    T * arr;
    int count;
    int size;

    public:
        Queue(int _size){
            size = _size;
            arr = new T[size];
            count = 0;
        }

        void enqueue(T data){
            if (count == size){
                cout << "Queue is full." << endl;
                return;
            }

            arr[count] = data;
            count++;
        }

        T dequeue(){
            if (count == 0) return *new T;

            T returnData = arr[0];

            for (int i = 1;i < count;i++){
                arr[i-1] = arr[i];
            }

            count--;

            return returnData;
        }

        int queueSize(){
            return count;
        }

        T front(){
            return arr[0];
        }

        T rear(){
            return arr[count - 1];
        }

        bool isEmpty(){
            return (count < 1) ? true : false;
        }

        void printQueue(){
            cout << "Printing queue from front to rear:" << endl;
            for (int i = 0;i < count;i++){
                cout << arr[i] << endl;
            }
        }
};