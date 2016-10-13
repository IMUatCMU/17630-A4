//
//  quick_sort.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-13.
//  Copyright © 2016 17630. All rights reserved.
//

#include "quick_sort.hpp"
#include "linked_list.hpp"
#include <iostream>

void QuickSort::quickSort(Sortable *sortable, int left, int right)
{
    int pvtIndex, l = left, r = right;
    bool inOrder = true;
    
    if (l == r)
        return;
    
    if (!sortable->less(l, l + 1))
        pvtIndex = l;
    else
        pvtIndex = l + 1;
    
    while (l < r)
    {
        while (sortable->less(l, pvtIndex) && (l < r))
            l++;
        while (!sortable->less(r, pvtIndex) && (l < r))
            r--;
        
        if (l != r)
        {
            if (pvtIndex == l)
                pvtIndex = r;
            else if (pvtIndex == r)
                pvtIndex = l;
            
            sortable->swap(l, r);
            inOrder = false;
        }
    }
    
    if (!inOrder)
    {
        this->quickSort(sortable, left, l-1);
        this->quickSort(sortable, l, right);
    }
}

void QuickSort::sort(Sortable *sortable)
{
    this->quickSort(sortable, 0, sortable->length() - 1);
}
