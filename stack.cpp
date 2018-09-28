#include <iostream>
#include "stack.hpp"

using namespace std;

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