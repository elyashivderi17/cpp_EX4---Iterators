#include "iostream"

namespace itertools {
    
    template <typename T1, typename T2> 
    class zip {
    
    private: 
     T1 iter_1;
     T2 iter_2;

    public:
        zip(T1 start, T2 end) :  iter_1(start), iter_2(end) {
        }
        
    auto begin() { 
        return  iterator<decltype(iter_1.begin()),decltype(iter_2.begin())>(iter_1.begin(), iter_2.begin());
         } 

    auto end() {
        return iterator<decltype(iter_1.end()),decltype(iter_2.end())>(iter_1.end(), iter_2.end());
         }  
 
    template <typename T3, typename T4>
        class iterator {

        private:
            T3 iter_3; 
            T4 iter_4;

        public:
            iterator(T3 A , T4 B): iter_3(A) , iter_4(B)  {}
            iterator<T3,T4>& operator++() {
               ++iter_3;
               ++iter_4;
               return *this;
            }

            std::pair<decltype(*iter_3),decltype(*iter_4)> operator*() const {
             return  std::pair<decltype(*iter_3),decltype(*iter_4)> (*iter_3 , *iter_4);
            }

            bool operator!=(iterator<T3,T4>  Temp) {
                return (iter_3 != Temp.iter_3) && (iter_4 != Temp.iter_4);
            }
        }; 
    };

    template <typename T,typename E>
    std::ostream &operator<<(std::ostream &Temp_2, const std::pair<T,E> &N) {
    Temp_2 << N.first << ',' << N.second;
    return Temp_2;
 }
}
