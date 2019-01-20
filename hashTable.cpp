#include <iostream>
#include <vector>
#include "hashTable.hpp"

using namespace std;

int main(){
    HashTable<int> ht;

    ht.set("hello", 5);
    ht.set("hello", 11);
    ht.set("banana", 882);
    ht.set("apple", 882);
    ht.set("apple", 889);
    ht.set("orange", 77);

    ht.unset("hello");

    try {
        cout << "hello: " << ht.get("hello") << endl;
    } catch(...){
        cout << "Key not valid." << endl;
    }

    try {
        cout << "banana: " << ht.get("banana") << endl;
    } catch(...){
        cout << "Key not valid." << endl;
    }

    ht.keyValues();
    return 0;
}