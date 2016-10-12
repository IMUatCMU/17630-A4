//
//  linked_list.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#include "linked_list.hpp"

LinkedList::LinkedList()
{
    this->head = NULL;
    this->size = 0;
}

void LinkedList::add(int index, Node *elem)
{
    // index range check
    if (index < 0 || index > this->count())
    {
        return;
    }
    
    // input check
    if (elem == NULL)
    {
        return;
    }
    
    // special case of the first elem
    if (this->count() == 0)
    {
        this->head = elem;
        this->tail = elem;
    }
    
    // there are already something in the list
    else
    {
        // special case of inserting before the head
        if (index == 0)
        {
            this->head->setPrev(elem);
        }
        
        // normal case: find the previous element and set next as elem
        else
        {
            Node* p = this->get(index - 1);
            if (p != NULL)
            {
                p->setNext(elem);
            }
        }
        
        // mark as head if elem is the first
        if (!elem->hasPrev())
        {
            this->head = elem;
        }
        
        // mark as tail if elem is the last
        if (!elem->hasNext())
        {
            this->tail = elem;
        }
    }
    
    // increment size
    this->size++;
}

Node* LinkedList::get(int index)
{
    // return NULL when the list is empty
    if (this->count() == 0)
    {
        return NULL;
    }
    
    // return NULL when the requested index is out of range
    if (index < 0 || index > this->count() - 1)
    {
        return NULL;
    }
    
    Node* cur = NULL;
    
    // traverse from the start if the index is on the first half
    if (index < this->count() / 2)
    {
        int c = 0;
        for (cur = this->head; c < index; cur = cur->getNext())
        {
            c++;
        }
    }
    
    // traverse from the end if the index if on the second half
    else
    {
        int c = this->count() - 1;
        for (cur = this->tail; c > index; cur = cur->getPrev())
        {
            c--;
        }
    }
    
    return cur;
}

void LinkedList::remove(int index)
{
    // index range check
    if (index < 0 || index > this->count() - 1)
    {
        return;
    }
    
    // removing the head
    if (index == 0)
    {
        this->head = this->head->getNext();
        if (this->head != NULL)
        {
            this->head->setPrev(NULL);
        }
    }
    
    // removing the tail
    else if (index == this->count() - 1)
    {
        this->tail = this->tail->getPrev();
        if (this->tail != NULL)
        {
            this->tail->setNext(NULL);
        }
    }
    
    // removing something in the middle
    else
    {
        Node *c = this->get(index);
        c->getPrev()->setNext(c->getNext());
    }
    
    // decrement size
    this->size--;
}

int LinkedList::count()
{
    return this->size;
}

LinkedList::~LinkedList()
{
    Node* p = this->head;
    Node* q = this->head;
    while(q)
    {
        p = q;
        q = p->getNext();
        if (q) delete p;
    }
    delete p;
}
