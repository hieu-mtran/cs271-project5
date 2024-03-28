//============================================================================
// Hieu Tran, Max Wisnefski, Aidan Jeansonne
// March 2024
// BTNode.h
// This is the header file for the Binary Tree node class
//============================================================================
#ifndef BTNODE_H
#define BTNODE_H

#include <iostream>
#include <string>
#include "BinaryTree.h"
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


    BTNode() {
        data = '\0';
        count = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    BTNode(char letter, int freq) {
        data = letter;
        count = freq;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

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
#endif