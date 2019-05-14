#include "iostream"
#include <iostream>

struct EmptyIterable {
    int* begin() const { return nullptr; }
    int* end() const { return nullptr; }
};

template<typename T1>
   EmptyIterable powerset(T1 a) { 
       return EmptyIterable{}; 
       }
