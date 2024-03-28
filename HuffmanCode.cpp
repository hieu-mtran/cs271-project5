//============================================================================
// Hieu Tran, Max Wisnefski, Aidan Jeansonne
// March 2024
// HuffmanCode.cpp
// This is the implementation file for the HuffmanCode class.
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include "HuffmanCode.h"

using namespace std;

/*
 * createFreqTable.
 * Description: creates a frequency table map, mapping the character to its frequency.
 * Parameters: string counts: a string of 26 integer frequencies separated by new lines, where the freq of a is on the first line.
 * Return: map<char, int> freqTable: a map of letters to their frequency.
 */
map<char, int> HuffmanCode::createFreqTable(string counts) {

    map<char, int> freqTable;

    string curr; // The current frequency number
    int idx = 0; // The current index for freqs
    int freqs[26]; // Array where each value is the freq for that letter (a being index 0)

    // Convert new line separated freqs to array.
    for (char val : counts){
        if (val == '\n')
        {
            freqs[idx] = stoi(curr);
            idx++;
            curr = "";
        }
        else {
            curr += val;
        }
    }

    // Populate the map.
    idx = 0;
    for (char letter = 'a'; letter <= 'z'; letter++)
    {
        freqTable[letter] = freqs[idx];
        idx++;
    }
    return freqTable;
}

/*
 * freqToBinaryTree.
 * Description: converts letter and freq to a one node binary tree storing that information.
 * Parameters: char letter: the letter to be stored, int freq: the freq of that letter.
 * Return: BinaryTree<char>* tree: the newly created one node binary tree.
 */
BinaryTree<char>* HuffmanCode::freqToBinaryTree(char letter, int freq){
    BTNode* node = new BTNode(letter, freq);

    BinaryTree<char>* tree = new BinaryTree<char>();
    tree->insert(node);

    return tree;
}

priority_queue<BinaryTree<char>*, vector<BinaryTree<char>*>, greater<BinaryTree<char>*>> HuffmanCode::freqTableToPQ(const map<char, int>& freqTable) {
    int freq;
    for (char ltr = 'a'; ltr <= 'z'; ltr++)
    {
        freq = freqTable.at(ltr);
        BinaryTree<char>* tree = freqToBinaryTree(ltr, freq);
        pq.push(tree);
    }
    return pq;
}


BinaryTree<char>* HuffmanCode::pqToHuffmanTree(){
    while (pq.size() > 1)
    {
        BinaryTree<char>* tree1 = pq.top();
        pq.pop();
        BinaryTree<char>* tree2 = pq.top();
        pq.pop();

        BinaryTree<char> combinedTree;
        combinedTree = combinedTree.merge(*tree1, *tree2);

        pq.push(&combinedTree);
    }
    return pq.top();
}

map<char, string> HuffmanCode::createEncodings(const BinaryTree<char>* huffTree) {
    map<char, string> encodings;
    string code;
    BTNode* root = huffTree->getRoot();
    encodingHelper(code, root, encodings);
    return encodings;
}

void HuffmanCode::encodingHelper(string currCode, const BTNode* currNode, map<char, string> encodings){
    if (currNode->isLeaf())
    {
        encodings[currNode->getData()] = currCode;
    }
    else {
        encodingHelper(currCode + "0", currNode->getLeft(), encodings);
        encodingHelper(currCode + "1", currNode->getRight(), encodings);
    }
}