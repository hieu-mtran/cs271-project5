//============================================================================
// Hieu Tran, Max Wisnefski, Aidan Jeansonne
// March 2024
// BinaryTree.cpp
// This is the implementation file for the BinaryTree class.
//============================================================================

#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

//============================================================================
// Default constructor
// Creates a new Binary Tree
//============================================================================
template<class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

//============================================================================
// Destructor
// Deallocates the memory used by a Binary Tree
//============================================================================
template<class T>
BinaryTree<T>::~BinaryTree()
{
    clear(root);
}

//============================================================================
// Assignment operator
//============================================================================
template<class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other)
{
    if (this != &other)
    {
        clear(root);
        root = copy(other.root);
    }
    return *this;
}


//============================================================================
// copy
// Makes a copy of a node and its children
//============================================================================
template<class T>
BTNode* BinaryTree<T>::copy(BTNode* node) const
{
    if (node == NULL) 
        return NULL;

    BTNode* z = new BTNode;
    z->data = node->data;
    z->count = node->count;
    z->left = copy(node->left);
    z->right = copy(node->right);
    z->parent = NULL;

    return z;
}

template<class T>
BTNode* BinaryTree<T>::getRoot() const
{
    return root;
}
//============================================================================
// insert
// Inserts a new node into a binary tree (with BST properties)
//============================================================================
template<class T>
void BinaryTree<T>::insert(BTNode* node)
{
    BTNode* x = root;
    BTNode* y = NULL;

    while (x != NULL) {
        y = x;
        if (node->data < x->data) 
            x = x->left;
        else 
            x = x->right;
    }

    node->parent = y;
    if (y == NULL)
        root = node;  
    else if (node->data < y->data)
        y->left = node;
    else
        y->right = node;
}

template<class T>
void BinaryTree<T>::insert(const char& character, const string& code) 
{
    if (root == nullptr) {
        root = new BTNode(character, 0); // Assuming count is initialized to 0
    }

    BTNode* current = root;
    for (char bit : code) {
        if (bit == '0') {
            if (current->left == nullptr) {
                current->left = new BTNode(' ', 0); // Placeholder node
                current->left->parent = current;
            }
            current = current->left;
        } else {
            if (current->right == nullptr) {
                current->right = new BTNode(' ', 0); // Placeholder node
                current->right->parent = current;
            }
            current = current->right;
        }
    }

    // Update the node with the character and its count
    current->data = character;
    current->count = 0;
}

//============================================================================
// merge & mergeTrees
// Merges two BSTs into one
//============================================================================
template<typename T>
BinaryTree<T> BinaryTree<T>::merge(const BinaryTree<T>& tree1, const BinaryTree<T>& tree2) const 
{
    BinaryTree<T> mergedTree;
    mergedTree.root = new BTNode();
    if (tree1.root != nullptr) {
        mergedTree.root->count += tree1.root->count;
    }
    if (tree2.root != nullptr) {
        mergedTree.root->count += tree2.root->count;
    }

    mergedTree.root->left = copy(tree1.root);
    mergedTree.root->right = copy(tree2.root);

    return mergedTree;
}

// Helper function for merge
template<typename T>
BTNode* BinaryTree<T>::mergeTrees(BTNode* root1, BTNode* root2) const {
    if (root1 == NULL) 
        return copy(root2);  // Copy tree2 if tree1 is empty
    if (root2 == NULL) 
        return copy(root1);  // Copy tree1 if tree2 is empty

    root1->count += root2->count;

    // Merge left and right subtrees recursively
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}

//============================================================================
// decode
// Decodes text encoded in binary 
// Returns: decoded string
// Inputs: encoded string
//============================================================================
template<class T>
string BinaryTree<T>::decode(const string& encodedText) {
    string decodedText;
    BTNode* current = root;

    for (char bit : encodedText) {
        // Check if the current bit is '0' and the left child exists
        if (bit == '0' && current->left != nullptr) {
            current = current->left;
        } 
        // Check if the current bit is '1' and the right child exists
        else if (bit == '1' && current->right != nullptr) {
            current = current->right;
        }
        // Check if the current bit is a newline character '\n'
        else if (bit == '\n') {
            // Add the newline character to the decoded text
            decodedText += '\n';
            // Reset current to the root for the next character
            current = root;
        }

        // Check if the current node's data is not a space
        if (current->data != ' ' && bit != '\n') {
            // Add the current node's data to the decoded text
            decodedText += current->data;
            // Reset current to the root for the next character
            current = root;
        }
    }
    return decodedText;
}

//============================================================================
// clear
// Deallocates a (sub)tree by using postorder traversal
//============================================================================
template<class T>
void BinaryTree<T>::clear(BTNode* node) 
{
    if (node) 
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template<class T>
bool BinaryTree<T>::operator>(const BinaryTree<T>& other) const {
    return root > other.root;
}

template<class T>
bool BinaryTree<T>::operator<(const BinaryTree<T>& other) const {
    return root < other.root;
}

template<class T>
bool BinaryTree<T>::operator>=(const BinaryTree<T>& other) const {
    return root >= other.root;
}

template<class T>
bool BinaryTree<T>::operator<=(const BinaryTree<T>& other) const {
    return root <= other.root;
}

template<class T>
bool BinaryTree<T>::operator==(const BinaryTree<T>& other) const {
    return root == other.root;
}

template<class T>
bool BinaryTree<T>::operator!=(const BinaryTree<T>& other) const {
    return root != other.root;
}
