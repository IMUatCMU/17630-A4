//
//  list.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#include "list.hpp"

void List::addFirst(Node *elem)
{
    this->add(0, elem);
}

void List::addLast(Node *elem)
{
    this->add(this->count(), elem);
}

Node* List::getFirst()
{
    return this->get(0);
}

Node* List::getLast()
{
    return this->get(this->count() - 1);
}

void List::removeFirst()
{
    this->remove(0);
}

void List::removeLast()
{
    this->remove(this->count() - 1);
}
