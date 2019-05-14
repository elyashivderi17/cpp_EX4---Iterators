namespace itertools {

template <class T>

class range {

private:
    T Start;
    T End;   

    class iterator {

    public:
        T Temp;
        iterator(T v) : Temp(v){}    
        bool operator!=(iterator const &other) const { 
            return Temp != (other.Temp);
        }

        T operator*() const {
            return Temp;
        }

        iterator &operator++() {
            ++Temp;
            return *this;
        }
    };

    public:
       range(T from, T to) : Start(from), End(to) {}                      
       iterator begin() const {
         return iterator(Start);
          }  
        iterator end() const { 
         return iterator(End); 
        }      
  }; 
} 
