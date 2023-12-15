#pragma once
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <cmath>

template<class T>
class Figure
{
protected:
    Figure() = default;

public:
    
    virtual ~Figure() = default;
    virtual operator double() const = 0;
    virtual std::pair<T,T> center() const = 0;
    virtual T area() const = 0;
};


