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
#include "BinaryTree.cpp"
using namespace std;


HuffmanCode::HuffmanCode() {
    pq = priority_queue<BinaryTree<BTNode*>*, vector<BinaryTree<BTNode*>*>, CompareBinaryTrees>();
}

HuffmanCode::~HuffmanCode() {
    while (pq.size() > 0) {
        delete pq.top();
        pq.pop();
    }
}

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
    for (int i = 0; i < counts.length(); i++){
        if (counts[i] == '\n') // Current number has ended.
        {
            freqs[idx] = stoi(curr); // Convert string number to int and store at current index.
            idx++;
            curr = ""; // Reset current string number.
        }
        else {
            curr += counts[i]; // Append next digit of the number to the string.
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
 * Return: BinaryTree<BTNode*>* tree: the newly created one node binary tree.
 */
BinaryTree<BTNode*>* HuffmanCode::freqToBinaryTree(char letter, int freq){
    BTNode* node = new BTNode(letter, freq); // New node with values.

    // New tree with one node at root
    BinaryTree<BTNode*>* tree = new BinaryTree<BTNode*>();
    tree->insert(node);

    return tree;
}

/*
 * freqTableToPQ.
 * Description: Converts a frequency table that maps letters to frequencies to a priority queue with the smallest frequencies at the top.
 * Parameters: map<char, int>&: the frequency table.
 * Return: priority queue pq: the pqueue of single node binary trees. pq is populated with the binary trees.
 */
priority_queue<BinaryTree<BTNode*>*, vector<BinaryTree<BTNode*>*>, CompareBinaryTrees> HuffmanCode::freqTableToPQ(const map<char, int>& freqTable) {
    int freq;
    for (char ltr = 'a'; ltr <= 'z'; ltr++) // Each val in freqTable.
    {
        freq = freqTable.at(ltr); 
        BinaryTree<BTNode*>* tree = freqToBinaryTree(ltr, freq); // Create single node binary tree.
        pq.push(tree); // Add tree to pq.
    }
    
    return pq;
}

/*
 * pqToHuffmanTree.
 * Description: converts a priority queue of single node binary trees to a huffman tree.
 * Parameters: none.
 * Return: BinaryTree<BTNode*> pq.top(): the only binary tree in the pqueue. The binary tree is a proper Huffman tree.
 */
BinaryTree<BTNode*>* HuffmanCode::pqToHuffmanTree(){
    while (pq.size() > 1) // Repeat until only one large combined tree in pq.
    {
        // cout << pq.top()->getRoot()->getCount() << endl;
        // Gets the two smallest trees.
        BinaryTree<BTNode*>* tree1 = pq.top();
        // cout << tree1->getRoot()->getData() << " ";
        pq.pop();
        BinaryTree<BTNode*>* tree2 = pq.top();
        // cout << tree2->getRoot()->getData() << " ";

        pq.pop();

        // Creates a combined tree.
        BinaryTree<BTNode*>* combinedTree = new BinaryTree<BTNode*>();
        *combinedTree = combinedTree->merge(*tree2, *tree1); // Greater on the left.
        // cout << combinedTree->getRoot()->getData() << endl;

        pq.push(combinedTree); // Adds combined tree back into the pq.
    }

    return pq.top(); // Returns the top/only value in pq.
}

/*
 * createEncodings.
 * Description: uses a huffman binary tree to create a map of letters and their huffman code.
 * Parameters: BinaryTree<BTNode*>* huffTree: the Huffman tree to be used to create the codes.
 * Return: map<char, string> encodings: a map of letters to their Huffman codes.
 */
map<char, string> HuffmanCode::createEncodings(const BinaryTree<BTNode*>* huffTree) {
    // cout << huffTree->getRoot()->getData();
    map<char, string> encodings; 
    string code = ""; // Empty to start.
    BTNode* root = huffTree->getRoot(); // Starting at the root node.
    encodingHelper(code, root, encodings);
    return encodings; // Return the final mapping.
}

/*
 * encodingHelper.
 * Description: used with createEncodings() to help create the encodings. For every move to the left, a 0 is added to the code,
 * and for every move to the right, a 1 is added to the code.
 * Parameters: string currCode: the current Huffman code, BTNode* currNode: the current node,
 * map<char, string> encodings: the map of encodings.
 * Return: None. encodings is fully populated for the tree.
 */
void HuffmanCode::encodingHelper(string currCode, const BTNode* currNode, map<char, string> &encodings){
    cout << currCode <<endl;
    if (currNode == nullptr) // When a node is not a leaf, but missing a child.
    {
        return;
    }
    
    if (currNode->isLeaf())
    {
        encodings[currNode->getData()] = currCode; // Append the letter and its encoding if it is the leaf.
    }
    else { // There are children of the node.
        encodingHelper(currCode + "0", currNode->getLeft(), encodings); // Add 0 to code and move left.
        encodingHelper(currCode + "1", currNode->getRight(), encodings); // Add 1 to code and move right.
    }
}

/*
 * encodingsToString.
 * Description: converts the encodings map to the proper string representation.
 * Parameters: map<char, string> encodings: the map of encodings.
 * Return: string encodingsText: the representation of the encodings.
 */
string HuffmanCode::encodingsToString(map<char, string> encodings) {
    string encodingsText = "";
    for (char letter = 'a'; letter <= 'y'; letter++)
    {
        encodingsText += letter;
        encodingsText += " ";
        encodingsText += encodings[letter];
        encodingsText += "\n";
        // cout << encodings.at(letter) << endl;
    }
    encodingsText += 'z';
    encodingsText += ' ';
    encodingsText += encodings['z']; // No new line after last character.
    return encodingsText;
    
}
