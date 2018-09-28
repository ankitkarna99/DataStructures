#include <iostream>
#include "stackFromArray.hpp"

using namespace std;

int main(){
    Stack<int> intStack;
    cout << "Empty?? : " << intStack.isEmpty() << endl;
    intStack.push(11);
    intStack.push(12);
    intStack.push(13);
    cout << "Popped: " << intStack.pop() << endl;
    intStack.displayStack();
    cout << "Empty?? : " << intStack.isEmpty() << endl;
    cout << "Peeking: " << intStack.peek() << endl;
    cout << "Stack size: " << intStack.stackSize() << endl;
    return 0;
}