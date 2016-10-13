//
//  sort.hpp
//  A4
//
//  Interface for all sorting algorithms
//
//  Created by Weinan Qiu on 2016-10-13.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef sort_hpp
#define sort_hpp

#include <stdio.h>
#include "sortable.hpp"

class Sort
{
public:
    
    // sort sortable in place
    virtual void sort(Sortable *sortable) = 0;
};

#endif /* sort_hpp */
