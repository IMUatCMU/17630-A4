//
//  bt_node.hpp
//  A4
//
//  A node in the binary tree
//
//  Created by Weinan Qiu on 2016-10-12.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef bt_node_hpp
#define bt_node_hpp

#include <stdio.h>
#include "data.hpp"

class BinaryTreeNode
{
private:
    Data            *data;
    BinaryTreeNode  *left;
    BinaryTreeNode  *right;
    int             balance;
    
public:
    BinaryTreeNode(Data *data);             // constructor
    int getBalance();                       // returns the balance factor
    void setBalance(int balance);           // set the balance factor
    BinaryTreeNode* getLeft();              // returns the left child
    BinaryTreeNode* getRight();             // returns the right child
    Data* getData();                        // return the data
    void appendLeft(BinaryTreeNode *node);  // append left child
    void appendRight(BinaryTreeNode *node); // append right child
    int nodeCount();                        // return the number of nodes, including self
    int height();                           // return the height of this node
    bool isLeaf();                          // returns true is the node is a leaf in tree
    ~BinaryTreeNode();                      // desctructor
};

#endif /* bt_node_hpp */
