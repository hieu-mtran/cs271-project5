//============================================================================
// Hieu Tran, Max Wisnefski, Aidan Jeansonne
// March 2024
// BinaryTree.h
// This is the header file for the Binary Tree class
//============================================================================

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
public:
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

    BTNode*         copy(BTNode* node);
    void            insert(const T& value);
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
