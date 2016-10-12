//
//  queue.hpp
//  A4
//
//  A Queue provides abstraction for queue ADT
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
#include "node.hpp"

class Queue
{
public:
    virtual void offer(Node* elem) = 0;         // offer a new element to the queue
    virtual Node* poll() = 0;                   // poll an element from the queue, NULL if empty
    virtual Node* peek() = 0;                   // return the element on top, but does not remove, return NULL if empty
    virtual int count() = 0;                    // return the size of this queue
    
    bool isEmpty();                         // convenience method to check if the size is 0
};

#endif /* queue_hpp */
