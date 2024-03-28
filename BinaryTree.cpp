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
// Default Node constructor
// Creates a new Binary Tree Node
//============================================================================

BTNode::BTNode()
{
    data = 0;
    count = 0;
}


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
// copy
// Makes a copy of a node and its children
//============================================================================
template<class T>
BTNode* BinaryTree<T>::copy(BTNode* node) 
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

//============================================================================
// insert
// Inserts a new node into a binary tree (with BST properties)
//============================================================================
template<class T>
void BinaryTree<T>::insert(const T& value)
{
    BTNode* z = new BTNode;
    z->data = value;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;

    BTNode* x = root;
    BTNode* y = NULL;

    while (x != NULL) {
        y = x;
        if (z->data < x->data) 
            x = x->left;
        else 
            x = x->right;
    }

    z->parent = y;
    if (y == NULL)
        root = z;  
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;
}

//============================================================================
// merge & mergeTrees
// Merges two BSTs into one
//============================================================================
template<typename T>
BinaryTree<T> BinaryTree<T>::merge(const BinaryTree<T>& tree1, const BinaryTree<T>& tree2) const 
{
    BinaryTree<T> mergedTree;

    // Copy tree1 and tree2 into mergedTree
    mergedTree.root = copy(tree1.root);
    mergedTree.root = mergeTrees(mergedTree.root, tree2.root);

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