//
//  stack.hpp
//  A4
//
//  A Stack provides abstraction for stack ADT
//
//  Created by Weinan Qiu on 2016-10-12.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include "node.hpp"

class Stack
{
public:
    virtual void push(Node* elem) = 0;          // push a new element onto the stack
    virtual Node* pop() = 0;                    // pop an element off the stack, NULL if empty
    virtual Node* peek() = 0;                   // return the element on top, but does not remove, return NULL if empty
    virtual int count() = 0;                    // return the size of this stack
    
    bool isEmpty();                             // convenience method to check if the size is 0
};

#endif /* stack_hpp */

