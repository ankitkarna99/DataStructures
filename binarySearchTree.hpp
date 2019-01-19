#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Node {
    public:
        Node *left;
        Node *right;
        T value;

        Node(T _value){
            left = nullptr;
            right = nullptr;
            value = _value;
        }
};

template <class T>
class BinarySearchTree {
    private:
        Node<T> *root;
        int count;

        void insertTo(Node<T> *node, T value){
            if(node->value > value){
                if (node->left == nullptr){
                    node->left = new Node<T>(value);
                } else {
                    insertTo(node->left, value);
                }
            } else {
                if (node->right == nullptr){
                    node->right = new Node<T>(value);
                    } else {
                        insertTo(node->right, value);
                    }
                }
        }

        Node<T>* findWithParent(T element, Node<T> * & parentNode){
            Node<T> *currentNode = root;
            parentNode = nullptr;

            if (currentNode == nullptr){
                return currentNode;
            }

            while(currentNode != nullptr){
                if (currentNode->value > element){
                    parentNode = currentNode;
                    currentNode = currentNode->left;
                } else if (currentNode->value < element){
                    parentNode = currentNode;
                    currentNode = currentNode->right;
                } else {
                    break;
                }
            }

            return currentNode;            
        }

    public:
        BinarySearchTree(){
            root = nullptr;
            count = 0;
        }

        //Insert Element
        void insert(T value){
            if (count == 0){
                root = new Node<T>(value);
            } else {
                insertTo(root, value);
            }
            count++;
        }

        void insert(vector<T> vals){
            for (auto val : vals){
                insert(val);
            }
        }

        Node<T>* find(T element){
            Node<T> *parentNode;
            return findWithParent(element, parentNode);
        }

        void remove(T element){
            Node<T> *parentNode;
            Node<T> *currentNode = findWithParent(element, parentNode);

            //Node not found            
            if (currentNode == nullptr) return;

            count--;

            if (currentNode->right == nullptr){
                if (parentNode == nullptr){
                    root = currentNode->left;
                } else {
                    if (currentNode->value < parentNode->value){
                        parentNode->left = currentNode->left;
                    } else {
                        parentNode->right = currentNode->left;
                    }
                }
            } else if (currentNode->right->left == nullptr){
                currentNode->right->left = currentNode->left;
                if (parentNode == nullptr){
                    root = currentNode->right;
                } else {
                    if (currentNode->value < parentNode->value){
                        parentNode->left = currentNode->right;
                    } else {
                        parentNode->right = currentNode->right;
                    }
                }
            } else {
                Node<T> *leftMost = currentNode->right->left;
                Node<T> *leftMostParent = currentNode->right;
                while(leftMost->left != nullptr){
                    leftMostParent = leftMost;
                    leftMost = leftMost->left;
                }

                leftMostParent->left = leftMost->right;

                leftMost->left = currentNode->left;
                leftMost->right = currentNode->right;

                if (parentNode == nullptr){
                    root = leftMost;
                } else {
                    if (currentNode->value < parentNode->value){
                        parentNode->left = leftMost;
                    } else {
                        parentNode->right = leftMost;
                    }
                }
                
            }

        }

        void traverseInOrder(Node<T> *node){
            if (node == nullptr){
                return;
            } else {
                traverseInOrder(node->left);
                cout << node->value << endl;
                traverseInOrder(node->right);
            }
        }

        void print(){
            cout << "Printing tree [In-Order Traversal]:" << endl;
            traverseInOrder(root);
        }
};