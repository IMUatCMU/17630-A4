//
//  linked_list_queue.hpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef linked_list_queue_hpp
#define linked_list_queue_hpp

#include <stdio.h>
#include "queue.hpp"
#include "linked_list.hpp"

class LinkedListQueue : public Queue
{
private:
    LinkedList *list;
    
public:
    LinkedListQueue();          // constructor
    ~LinkedListQueue();         // destructor
    
    // implement Queue's method
    void offer(Node* elem);
    Node* poll();
    Node* peek();
    int count();
};

#endif /* linked_list_queue_hpp */
