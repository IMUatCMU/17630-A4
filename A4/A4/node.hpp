//
//  node.hpp
//  A4
//
//  A node is a single unit of data, it provides previous
//  and next pointers for easy chaining to be used in linear
//  structures such as linked list.
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <stdio.h>
#include <string>
#include "data.hpp"

using namespace std;

class Node
{
private:
    Data    *data;      // string field to store the data
    Node    *next;      // pointer to the next node
    Node    *prev;      // pointer to the previous node

public:
    Node(Data *data);   // constructor to accept data
    Node* getPrev();    // returns the prev pointer
    Node* getNext();    // returns the next pointer
    bool hasPrev();     // returns true if the *prev pointer isn't null, false otherwise
    bool hasNext();     // return true if the *next pointer isn't null, false otherwise
    Data* getData();   // return the data
    
    // set the *next pointer of this node and *prev of the new node
    // also supports new node being null
    void setNext(Node *newNode);
    
    // set the *prev pointer of this node and *next of the new node
    // also supports new node being null
    void setPrev(Node *newNode);
    
    ~Node();            // destructor
};

#endif /* node_hpp */
