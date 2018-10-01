#include <iostream>
#include "doublyLinkedList.hpp"

using namespace std;

int main(){
    DoublyLinkedList <int> myDLL;
    myDLL.addFront(5);
    myDLL.addFront(6);
    myDLL.addFront(7);
    myDLL.addFront(8);
    myDLL.addFront(9);
    myDLL.removeBack();
    myDLL.removeFront();
    myDLL.addBack(10);
    cout << "Size: " << myDLL.getSize() << endl;
    cout << "Front: " << myDLL.getFront() << endl;
    cout << "Back: " << myDLL.getBack() << endl;
    cout << "Printing list:" << endl;
    myDLL.displayList();
    Node<int> * searchResult = myDLL.find(7);
    cout << "Previous Node Data: " << searchResult->prev->data << endl;
    cout << "Found Node Data: " << searchResult->data << endl;
    cout << "Next Node Data: " << searchResult->next->data << endl;
    return 0;
}