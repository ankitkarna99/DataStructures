#include <iostream>

using namespace std;

template <class T>
class Stack {
    T * arr;
    int count;

    public:
        Stack(){
            arr = new T[0];
            count = 0;
        }

        void push(T data){
            T * newArr = new T[count + 1];
            for (int i = 0;i < count;i++){
                newArr[i] = arr[i];
            }
            newArr[count] = data;
            delete[] arr;
            arr = newArr;
            count++;
        }

        T pop(){
            T returnData;
            returnData = arr[count - 1];

            T *newArr = new T[count - 1];
            count--;
            for (int i = 0;i < count;i++){
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;

            return returnData;
        }

        int stackSize(){
            return count;
        }

        bool isEmpty(){
            return (count < 1) ? true : false;
        }

        T peek(){
            return arr[count - 1];
        }

        void displayStack(){
            cout << "Printing stack from top to bottom:" << endl;
            for (int i = count - 1;i >= 0;i--){
                cout << arr[i] << endl;
            }
        }
};