//
//  binary_tree.hpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-12.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef binary_tree_hpp
#define binary_tree_hpp

#include <stdio.h>
#include <functional>
#include "bt_node.hpp"

class BinaryTree
{
private:
    BinaryTreeNode *root;
    void innerAdd(BinaryTreeNode* parent, BinaryTreeNode *node);
    void reBalance(BinaryTreeNode* parent);                   // reset the balance factor of the nodes
    void preOrderInner(BinaryTreeNode* node, std::function <void(BinaryTreeNode*)> cb);
    void postOrderInner(BinaryTreeNode* node, std::function <void(BinaryTreeNode*)> cb);
    void inOrderInner(BinaryTreeNode* node, std::function <void(BinaryTreeNode*)> cb);
    
public:
    
    BinaryTree();                       // constructor
    ~BinaryTree();                      // destructor
    void add(BinaryTreeNode *node);     // add a node to the tree, maintaining the tree's balance
    void inOrder(std::function <void(BinaryTreeNode*)> cb);      // traverse in order, perform function on each node
    void preOrder(std::function <void(BinaryTreeNode*)> cb);     // traverse pre order, perform function on each node
    void postOrder(std::function <void(BinaryTreeNode*)> cb);    // traverse post order, perform function on each node
};

#endif /* binary_tree_hpp */
