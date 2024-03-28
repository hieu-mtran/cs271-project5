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

using namespace std;

class BTNode
{
private:
    char data;
    int count;
    BTNode* left;
    BTNode* right;
    BTNode* parent;

    template <typename> friend class BinaryTree;
public:
    BTNode();
    BTNode(char letter, int count);

    // Getter methods
    BTNode* getLeft() const {
        return left;
    }

    BTNode* getRight() const {
        return right;
    }

    BTNode* getParent() const {
        return parent;
    }

    char getData() const {
        return data;
    }

    bool isLeaf() const {
        return left == nullptr && right == nullptr;
    }

    // Comparison operators
    bool operator>(const BTNode& other) const 
    {
        return count > other.count;
    }

    bool operator<(const BTNode& other) const 
    {
        return count < other.count;
    }

    bool operator>=(const BTNode& other) const 
    {
        return count >= other.count;
    }

    bool operator<=(const BTNode& other) const 
    {
        return count <= other.count;
    }

    bool operator==(const BTNode& other) const 
    {
        return count == other.count;
    }

    bool operator!=(const BTNode& other) const 
    {
        return count != other.count;
    }
};


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
    BinaryTree<T>   merge(const BinaryTree<T>& tree1, const BinaryTree<T>& tree2) const;
    BTNode*         mergeTrees(BTNode* root1, BTNode* root2) const; // helper function for merge
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