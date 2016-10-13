//
//  quick_sort.hpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-13.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef quick_sort_hpp
#define quick_sort_hpp

#include <stdio.h>
#include "sort.hpp"

class QuickSort : public Sort
{
private:
    void quickSort(Sortable *sortable, int left, int right);
    
public:
    void sort(Sortable *sortable);
};

#endif /* quick_sort_hpp */
