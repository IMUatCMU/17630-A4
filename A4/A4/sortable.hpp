//
//  sortable.hpp
//  A4
//
//  Sortable is an interface that provides implementations the ability to be used by a sorting algorithm
//
//  Created by Weinan Qiu on 2016-10-13.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef sortable_hpp
#define sortable_hpp

#include <stdio.h>
#include "comparable.hpp"

class Sortable
{
public:
    virtual int length() = 0;               // return the total length of the subject
    virtual void swap(int i, int j) = 0;    // swap item at index i and index j
    virtual bool less(int i, int j) = 0;    // return true if item at index i is less than index j
};

#endif /* sortable_hpp */
