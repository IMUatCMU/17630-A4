//
//  linked_list_stack.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-12.
//  Copyright © 2016 17630. All rights reserved.
//

#include "linked_list_stack.hpp"

LinkedListStack::LinkedListStack()
{
    this->list = new LinkedList();
}

void LinkedListStack::push(Node* elem)
{
    this->list->addFirst(elem);
}

Node* LinkedListStack::pop()
{
    Node* first = this->list->getFirst();
    this->list->removeFirst();
    return first;
}

Node* LinkedListStack::peek()
{
    return this->list->getFirst();
}

int LinkedListStack::count()
{
    return this->list->count();
}

LinkedListStack::~LinkedListStack()
{
    delete this->list;
}
