//
//  linked_list.hpp
//  A4
//
//  A doubly linked list implementation to List
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef linked_list_hpp
#define linked_list_hpp

#include <stdio.h>
#include "list.hpp"
#include "node.hpp"

class LinkedList : public List
{
private:
    Node* head;
    Node* tail;
    int size;
    
public:
    LinkedList();           // default constructor
    ~LinkedList();          // default destructor
    
    // implements List virtual methods
    void add(int index, Node *elem);
    Node* get(int index);
    void remove(int index);     // note this method only removes the node from the list, it does not release its memory
    int count();
};

#endif /* linked_list_hpp */
