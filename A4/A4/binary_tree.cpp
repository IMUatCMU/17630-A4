//
//  binary_tree.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-12.
//  Copyright © 2016 17630. All rights reserved.
//

#include "binary_tree.hpp"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
    this->root = NULL;
}

BinaryTree::~BinaryTree()
{
    delete this->root;
}

void BinaryTree::add(BinaryTreeNode *node)
{
    // first node
    if (this->root == NULL)
    {
        this->root = node;
    }
    // not first node
    else
    {
        this->innerAdd(this->root, node);
    }
    
    this->reBalance(this->root);
}

void BinaryTree::innerAdd(BinaryTreeNode* parent, BinaryTreeNode *node)
{
    // right heavy or balanced, we add to the left
    if (parent->getBalance() >= 0)
    {
        if (parent->getLeft() == NULL)
        {
            parent->appendLeft(node);
        }
        else
        {
            this->innerAdd(parent->getLeft(), node);
        }
    }
    // left heavy, we add to the right
    else
    {
        if (parent->getRight() == NULL)
        {
            parent->appendRight(node);
        }
        else
        {
            this->innerAdd(parent->getRight(), node);
        }
    }
}

void BinaryTree::reBalance(BinaryTreeNode* parent)
{
    int leftHeight = 0, rightHeight = 0;
    if (parent->getLeft())
    {
        this->reBalance(parent->getLeft());
        leftHeight = parent->getLeft()->height() + 1;
    }
    if (parent->getRight())
    {
        this->reBalance(parent->getRight());
        rightHeight = parent->getRight()->height() + 1;
    }
    parent->setBalance(rightHeight - leftHeight);
}

void BinaryTree::preOrder(std::function <void(BinaryTreeNode*)> cb)
{
    this->preOrderInner(this->root, cb);
}

void BinaryTree::postOrder(std::function <void(BinaryTreeNode*)> cb)
{
    this->postOrderInner(this->root, cb);
}

void BinaryTree::inOrder(std::function<void (BinaryTreeNode *)> cb)
{
    this->inOrderInner(this->root, cb);
}

void BinaryTree::preOrderInner(BinaryTreeNode *node, std::function <void(BinaryTreeNode*)> cb)
{
    if (node == NULL)
        return;
    
    cb(node);
    this->preOrderInner(node->getLeft(), cb);
    this->preOrderInner(node->getRight(), cb);
}

void BinaryTree::postOrderInner(BinaryTreeNode *node, std::function <void(BinaryTreeNode*)> cb)
{
    if (node == NULL)
        return;
    
    this->postOrderInner(node->getLeft(), cb);
    this->postOrderInner(node->getRight(), cb);
    cb(node);
}

void BinaryTree::inOrderInner(BinaryTreeNode* node, std::function <void(BinaryTreeNode*)> cb)
{
    if (node == NULL)
        return;
    
    this->postOrderInner(node->getLeft(), cb);
    cb(node);
    this->postOrderInner(node->getRight(), cb);
}
