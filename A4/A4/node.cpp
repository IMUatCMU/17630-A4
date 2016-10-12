//
//  node.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#include "node.hpp"

Node::Node(string data)
{
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
}

Node* Node::getPrev()
{
    return this->prev;
}

Node* Node::getNext()
{
    return this->next;
}

bool Node::hasPrev()
{
    return this->prev != NULL;
}

bool Node::hasNext()
{
    return this->next != NULL;
}

string Node::getData()
{
    return this->data;
}

void Node::setNext(Node *newNode)
{
    if (this->hasNext())
    {
        this->getNext()->prev = NULL;
    }
    this->next = newNode;
    if (this->hasNext() && this->getNext()->getPrev() != this)
    {
        this->getNext()->setPrev(this);
    }
}

void Node::setPrev(Node *newNode)
{
    if (this->hasPrev())
    {
        this->getPrev()->next = NULL;
    }
    this->prev = newNode;
    if (this->hasPrev() && this->getPrev()->getNext() != this)
    {
        this->getPrev()->setNext(this);
    }
}

Node::~Node()
{
    this->prev = NULL;
    this->next = NULL;
    delete this;
}
