//============================================================================
// Hieu Tran, Max Wisnefski, Aidan Jeansonne
// March 2024
// HuffmanCode.h
// This is the header file for the Huffman Code class
//============================================================================

#include <iostream>
#include <string>
#include <queue>
#include "BinaryTree.cpp"


using namespace std;

class HuffmanCode
{
public:
    HuffmanCode();
    ~HuffmanCode();




private:

    priority_queue<BinaryTree<char>, vector<BinaryTree<char>>, greater<BinaryTree<char>>> pq; // pqueue of type BinaryTree<char>, stored using vector, smallest element at top.

};