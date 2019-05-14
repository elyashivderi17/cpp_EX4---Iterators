#include "iostream"

namespace itertools {
    
    template <typename T1, typename T2> 
    class chain {
    
    private: 
        T1 iter_1;
        T2 iter_2;

    public:
        chain(T1 start, T2 end) :  iter_1(start), iter_2(end) {}   

    auto begin(){ 
        return  iterator<decltype(iter_1.begin()),decltype(iter_2.begin())>(iter_1.begin(), iter_2.begin()); }  

    auto end() {
        return iterator<decltype(iter_1.end()),decltype(iter_2.end())>(iter_1.end(), iter_2.end()); }  
 
    template <typename T3, typename T4>
        class iterator {

        private:
            T3 iter_3; 
            T4 iter_4; 
         bool Check;

        public:
            iterator(T3 A, T4 B): iter_3(A) , iter_4(B), Check(true)  {}

           iterator<T3,T4>& operator++() {
                if(Check){
                    ++iter_3;
                }else {
                    ++iter_4;
                }
                return *this;
            }

            decltype(*iter_3) operator*() const {

                if(Check){
                    return *iter_3;
                }else {
                    return *iter_4;
                }
            }

            bool operator!=(iterator<T3,T4>Temp){
                if(Check && !(iter_3 != Temp.iter_3)){
                    Check = false;
                }
                if(Check){
                    return iter_3 != Temp.iter_3;
                }else{
                    return iter_4 != Temp.iter_4;
                }
            }
         
        }; 

    };
}
