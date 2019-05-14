#include "iostream"
#include <iostream>

struct EmptyIterable {
    int* begin() const { return nullptr; }
    int* end() const { return nullptr; }
};

 template <typename T1, typename T2>
   EmptyIterable product(T1 a,T2 b) { 
       return EmptyIterable{}; 
       }
