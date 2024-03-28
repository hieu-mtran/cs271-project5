#include <iostream>
#include "HuffmanCode.h"
#include "BinaryTree.h"

using namespace std;

int main() {
    // Example string of frequencies
    string counts = "204420\n34372\n60660\n117752\n313026\n54507\n50909\n166520\n172641\n2485\n20282\n96036\n61283\n183130\n191492\n44717\n2319\n146890\n162130\n224510\n64918\n26788\n58930\n4032\n45937\n2385";

    // Create HuffmanCode object
    HuffmanCode huffman;

    // Create frequency table
    map<char, int> freqTable = huffman.createFreqTable(counts);

    // Convert frequency table to priority queue of binary trees
    priority_queue<BinaryTree<BTNode*>*, vector<BinaryTree<BTNode*>*>, CompareBinaryTrees > pq = huffman.freqTableToPQ(freqTable);

    // Convert priority queue to Huffman tree
    BinaryTree<BTNode*>* huffmanTree = huffman.pqToHuffmanTree();

    // Create encodings using Huffman tree
    map<char, string> encodings = huffman.createEncodings(huffmanTree);
    // cout << encodings.at('a');

    string s = huffman.encodingsToString(encodings);
    cout << s;



    // delete huffmanTree;

    return 0;
}