//============================================================================
// Hieu Tran, Max Wisnefski, Aidan Jeansonne
// March 2024
// HuffmanCode.h
// This is the header file for the Huffman Code class
//============================================================================
#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include "BinaryTree.h"

using namespace std;

// Need to use this for pqueue because some elements were out of order.
// Idea of using struct from cppreference priority_queue docs.
struct CompareBinaryTrees {
    bool operator()(const BinaryTree<BTNode*>* leftTree, const BinaryTree<BTNode*>* rightTree) const {
        return leftTree->getRoot()->getCount() > rightTree->getRoot()->getCount();
    }
};

class HuffmanCode
{
public:
    HuffmanCode();
    ~HuffmanCode();

    map<char, int>                      createFreqTable(string counts);
    BinaryTree<BTNode*>*                   freqToBinaryTree(char letter, int freq);
    priority_queue<BinaryTree<BTNode*>*, vector<BinaryTree<BTNode*>*>, CompareBinaryTrees> freqTableToPQ(const map<char, int>& freqTable);

    BinaryTree<BTNode*>*                   pqToHuffmanTree();
    map<char, string>                   createEncodings(const BinaryTree<BTNode*>* huffTree);

    string                              encodingsToString(map<char, string> encodings);
private:
    priority_queue<BinaryTree<BTNode*>*, vector<BinaryTree<BTNode*>*>, CompareBinaryTrees> pq;

    void                                encodingHelper(string currCode, const BTNode* currNode, map<char, string> &encodings);
};

#endif