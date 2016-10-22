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
#include <functional>
#include "list.hpp"
#include "node.hpp"

class LinkedList : public List
{
private:
    Node* head;
    Node* tail;
    int size;
    void addPreservingOrderInner(Node *elem, int start, int end);
    
public:
    LinkedList();           // default constructor
    ~LinkedList();          // default destructor
    
    // implements List virtual methods
    void add(int index, Node *elem);
    Node* get(int index);
    void remove(int index);     // note this method only removes the node from the list, it does not release its memory
    int count();
    void traverse(std::function<void(Node*)> cb);   // traverse the list and invoke callback for each node
    
    // implements Sortable virtual methods
    int length();
    void swap(int i, int j);
    bool less(int i, int j);
    void addPreservingOrder(Node *elem);
};

#endif /* linked_list_hpp */
