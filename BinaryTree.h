//============================================================================
// Hieu Tran, Max Wisnefski, Aidan Jeansonne
// March 2024
// BinaryTree.h
// This is the header file for the Binary Tree class
//============================================================================
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include "BTNode.h"
using namespace std;

template<class T>
class BinaryTree 
{
public:
    BinaryTree();
    ~BinaryTree();
    BinaryTree<T>& operator=(const BinaryTree<T>& other);

    BTNode*         getRoot() const;
    BTNode*         copy(BTNode* node) const;
    void            insert(BTNode* node);
    void            insert(const char& character, const string& code);
    BinaryTree<T>   merge(const BinaryTree<T>& tree1, const BinaryTree<T>& tree2) const;
    BTNode*         mergeTrees(BTNode* root1, BTNode* root2) const; // helper function for merge
    string          decode(const string& encodedText);
    void            clear(BTNode* node);                                  

    // Comparison operators
    bool operator>(const BinaryTree<T>& other) const;
    bool operator<(const BinaryTree<T>& other) const;
    bool operator>=(const BinaryTree<T>& other) const;
    bool operator<=(const BinaryTree<T>& other) const;
    bool operator==(const BinaryTree<T>& other) const;
    bool operator!=(const BinaryTree<T>& other) const;

private:
    BTNode* root;
};

#endif