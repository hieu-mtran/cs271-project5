#include <iostream>
#include "HuffmanCode.h"
#include "BinaryTree.h"

using namespace std;

int main() {
    // Example string of frequencies
    string counts = "10\n20\n30\n40\n50\n60\n70\n80\n90\n100\n110\n120\n130\n140\n150\n160\n170\n180\n190\n200\n210\n220\n230\n240\n250\n260\n";

    // Create HuffmanCode object
    HuffmanCode huffman;

    // Create frequency table
    map<char, int> freqTable = huffman.createFreqTable(counts);

    // Convert frequency table to priority queue of binary trees
    priority_queue<BinaryTree<BTNode>*, vector<BinaryTree<BTNode>*>, greater<BinaryTree<BTNode>*> > pq = huffman.freqTableToPQ(freqTable);

    // Convert priority queue to Huffman tree
    BinaryTree<BTNode>* huffmanTree = huffman.pqToHuffmanTree();

    // Create encodings using Huffman tree
    map<char, string> encodings = huffman.createEncodings(huffmanTree);
    cout << encodings.at('a');

    // string s = huffman.encodingsToString(encodings);
    // cout << s;


    // delete huffmanTree;

    return 0;
}