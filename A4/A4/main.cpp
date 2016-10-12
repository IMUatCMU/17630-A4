//
//  main.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#include <iostream>
#include "node.hpp"
#include "linked_list.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    LinkedList *list = new LinkedList();
    list->addLast(new Node("A"));
    list->addLast(new Node("B"));
    list->addLast(new Node("C"));
    list->addLast(new Node("D"));
    list->addFirst(new Node("X"));
    
    std::cout << list->count() << "\n";
    std::cout << list->get(0)->getData() << "\n";
    std::cout << list->get(1)->getData() << "\n";
    std::cout << list->get(2)->getData() << "\n";
    std::cout << list->get(3)->getData() << "\n";
    
    return 0;
}
