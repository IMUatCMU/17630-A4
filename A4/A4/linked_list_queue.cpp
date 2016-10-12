//
//  linked_list_queue.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#include "linked_list_queue.hpp"

LinkedListQueue::LinkedListQueue()
{
    this->list = new LinkedList();
}

LinkedListQueue::~LinkedListQueue()
{
    delete this->list;
}

Node* LinkedListQueue::poll()
{
    Node* elem = this->list->getFirst();
    this->list->removeFirst();
    return elem;
}

void LinkedListQueue::offer(Node *elem)
{
    this->list->addLast(elem);
}

Node* LinkedListQueue::peek()
{
    return this->list->getFirst();
}

int LinkedListQueue::count()
{
    return this->list->count();
}
