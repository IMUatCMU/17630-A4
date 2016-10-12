//
//  list.hpp
//  A4
//
//  A list provides abstraction for lists ADT
//  It defines common operations such as insert, remove, count, get and etc.
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include "node.hpp"

class List
{
    
public:
    virtual void add(int index, Node *elem) = 0;    // add the specified element at an index
    virtual Node* get(int index) = 0;               // get the element at specified index, NULL if not existing
    virtual void remove(int index) = 0;             // remove the element at specified index
    virtual int count() = 0;                        // count the size of the list
    virtual ~List() {}                              // empty virtual descructor
    
    void addFirst(Node* elem);                      // add the speciified element to the start of the list
    void addLast(Node* elem);                       // add the specified element to the end of the list
    Node* getFirst();                               // get the first element, NULL if not existing
    Node* getLast();                                // get the last element, NULL if not existing
    void removeLast();                              // remove the last element of the list
    void removeFirst();                             // remove the first element of the list
};

#endif /* list_hpp */
