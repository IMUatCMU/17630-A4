//
//  bt_node.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-12.
//  Copyright © 2016 17630. All rights reserved.
//

#include "bt_node.hpp"

BinaryTreeNode::BinaryTreeNode(Data *data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->balance = 0;
}

int BinaryTreeNode::getBalance()
{
    return this->balance;
}

void BinaryTreeNode::setBalance(int balance)
{
    this->balance = balance;
}

BinaryTreeNode* BinaryTreeNode::getLeft()
{
    return this->left;
}

BinaryTreeNode* BinaryTreeNode::getRight()
{
    return this->right;
}

Data* BinaryTreeNode::getData()
{
    return this->data;
}

void BinaryTreeNode::appendLeft(BinaryTreeNode *node)
{
    this->left = node;
}

void BinaryTreeNode::appendRight(BinaryTreeNode *node)
{
    this->right = node;
}

int BinaryTreeNode::nodeCount()
{
    if (this->isLeaf())
    {
        return 1;
    }
    
    int count = 0;
    if (this->left != NULL)
        count += this->left->nodeCount();
    if (this->right != NULL)
        count += this->right->nodeCount();
    
    return count + 1;
}

int BinaryTreeNode::height()
{
    if (this->isLeaf())
        return 0;
    
    int leftHeight = 0, rightHeight = 0;
    if (this->left)
        leftHeight = this->left->height();
    if (this->right)
        rightHeight = this->right->height();
    return std::max(leftHeight, rightHeight) + 1;
}

bool BinaryTreeNode::isLeaf()
{
    return this->left == NULL && this->right == NULL;
}

BinaryTreeNode::~BinaryTreeNode()
{
    delete this->left;
    delete this->right;        
}
