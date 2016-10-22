//
//  linked_list_stack.hpp
//  A4
//
//  A linked list implementation of the stack.
//
//  Created by Weinan Qiu on 2016-10-12.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef linked_list_stack_hpp
#define linked_list_stack_hpp

#include <stdio.h>
#include "stack.hpp"
#include "list.hpp"
#include "node.hpp"

class LinkedListStack : public Stack
{
private:
    List *list;
    
public:
    LinkedListStack();          // constructor
    ~LinkedListStack();         // destructor
    
    // implement Stack's methods
    void push(Node* elem);
    Node* pop();
    Node* peek();
    int count();
};

#endif /* linked_list_stack_hpp */
