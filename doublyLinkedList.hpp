#include <iostream>

using namespace std;

template <class T>
class Node {
    public:
        T data;
        Node *next;
        Node *prev;
        Node(){}

        Node(int _data){
            data = _data;
        }
};

template <class T>
class DoublyLinkedList {
    private:
        Node<T> *head;
        Node<T> *tail;
        int count;

    public:

        DoublyLinkedList(){
            count = 0;
            head = new Node<T>;
            tail = new Node<T>;
        }

        void addFront(T data){
            Node<T> *newNode = new Node<T>(data);
            if (count == 0){
                newNode->prev = NULL;
                newNode->next = NULL;
                head = newNode;
                tail = newNode;
            } else {
                newNode->prev = NULL;
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            count++;
        }

        void addBack(T data){
            Node<T> *newNode = new Node<T>(data);
            if (count == 0){
                newNode->prev = NULL;
                newNode->next = NULL;
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = NULL;
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }

            count++;
        }

        void removeFront(){
            if (count == 0) return;

            Node<T> *secondNode = head->next;
            secondNode->prev = NULL;
            delete head;
            head = secondNode;
            count--;
        }

        void removeBack(){
            if (count == 0) return;

            Node<T> *secondLastNode = tail->prev;
            secondLastNode->next = NULL;
            delete tail;
            tail = secondLastNode;
            count--;
        }

        T getFront(){
            return head->data;
        }

        T getBack(){
            return tail->data;
        }

        int getSize(){
            return count;
        }

        void displayList(){
            if (count == 0) return;

            Node<T> *node = head;

            while(node){
                cout << node->data << endl;
                node = node->next;
            }
        }
};