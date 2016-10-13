//
//  comparable.hpp
//  A4
//
//  Comparable is an interface that gives implementations the ability to compare to each other
//
//  Created by Weinan Qiu on 2016-10-13.
//  Copyright © 2016 17630. All rights reserved.
//

#ifndef comparable_hpp
#define comparable_hpp

#include <stdio.h>

template <typename T>
class Comparable
{
public:
    virtual int compare(T *other) = 0;
};

#endif /* comparable_hpp */
