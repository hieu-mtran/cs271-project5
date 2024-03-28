//============================================================================
// Hieu Tran, Max Wisnefski, Aidan Jeansonne
// March 2024
// HuffmanCode.h
// This is the header file for the Huffman Code class
//============================================================================

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include "BinaryTree.cpp"


using namespace std;

class HuffmanCode
{
public:
    HuffmanCode();
    ~HuffmanCode();

    map<char, int>              createFreqTable(string counts);
    BinaryTree<char>            createHuffTree(const map<char, int>& freqTable);
    map<char, string>           createEncodings(const BinaryTree<char> huffTree);


private:

    priority_queue<BinaryTree<char>, vector<BinaryTree<char>>, greater<BinaryTree<char>>> pq; // pqueue of type BinaryTree<char>, stored using vector, smallest element at top.

};