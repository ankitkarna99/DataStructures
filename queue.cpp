#include <iostream>
#include "queue.hpp"

using namespace std;

int main(){
    Queue<int> intQueue;

    cout << "Empty: " << intQueue.isEmpty() << endl;

    intQueue.enqueue(5);
    intQueue.enqueue(6);
    intQueue.enqueue(7);

    cout << "Queue Size: " << intQueue.queueSize() << endl;

    cout << "Front: " << intQueue.front() << endl;
    cout << "Rear: " << intQueue.rear() << endl;

    cout << "Dequeued: " << intQueue.dequeue() << endl;

    cout << "Queue Size: " << intQueue.queueSize() << endl;

    intQueue.printQueue();

    cout << "Empty: " << intQueue.isEmpty() << endl;
    
    return 0;
}