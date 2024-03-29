#include <iostream>
#include "HuffmanCode.h"
#include "HuffmanCode.cpp"
#include "BinaryTree.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 1){
        cout << "Error: no file entered in command line" << endl;
        return -1;
    }
    
    string filename = argv[1]; 
    //cout << filename; 
    fstream f;
    f.open(filename);
    //read the 
    string counts = "";
    string tp;
    while(getline(f, tp)){ //reading each line of data
         //cout << tp << "\n"; 
         //adding each line of data to out counts string
         counts = counts + tp + "\n";
    }
    cout << counts << endl;

    f.close();

    

    // Example string of frequencies (used before we used command line input)
    //string counts = "204420\n34372\n60660\n117752\n313026\n54507\n50909\n166520\n172641\n2485\n20282\n96036\n61283\n183130\n191492\n44717\n2319\n146890\n162130\n224510\n64918\n26788\n58930\n4032\n45937\n2385";

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
    cout << s << endl;




    return 0;
}