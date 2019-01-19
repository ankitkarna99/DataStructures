#include <iostream>
#include <vector>
#include "binarySearchTree.hpp"

using namespace std;

int main(){
    BinarySearchTree<int> bst;

    vector<int> arr = {14, 23, 7, 10, 33, 56, 80, 66, 70, 44, 50, 40, 60};

    bst.insert(arr);

    bst.print();

    bst.remove(56);

    bst.print();

    return 0;
}