#include <iostream>

using namespace std;

template <class T>
class Node {
    public:
        T data;
        Node *next;

        Node(){
        }

        Node(T _data){
            data = _data;
        }
};

template <class T>
class LinkedList {
    private:
        int count;
        Node <T> *head, *tail;
    
    public:

        LinkedList(){
            count = 0;
            head = new Node<T>;
            tail = new Node<T>;
        }

        void addFront(T data){
            Node<T> *newNode = new Node<T>(data);
            if (count == 0){
                newNode->next = NULL;
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            count++;
        }

        void addBack(T data){
            Node<T> *newNode = new Node<T>(data);
            if (count == 0){
                newNode->next = NULL;
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = NULL;
                tail->next = newNode;
                tail = newNode;
            }
            count++;
        }

        void removeBack(){
            if (count == 0) return;
            Node<T> *node = head;
            while (node){
                if (node->next == tail){
                    delete tail;
                    node->next = NULL;
                    tail = node;
                    count--;
                    break;
                }
                node = node->next;
            }
        }

        T getFront(){
            return head->data;
        }

        int getSize(){
            return count;
        }

        void removeFront(){
            if (count == 0) return;

            Node<T> *temp = head->next;
            delete head;
            head = temp;

            count--;
        }

        void printList(){
            if (count == 0) return;
            Node<T> *node = head;
            while (node){
                cout << node->data << endl;
                node = node->next;
            }
        }
};