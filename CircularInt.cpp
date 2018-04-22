#include "CircularInt.hpp"

CircularInt::CircularInt(int x, int y) : start(x), end(y) {
    if(x>y){
        start = y;
        end = x;
    }
    number = start;
    range = end - start + 1;
}

CircularInt::CircularInt(const CircularInt& clone){
    start = clone.start;
    end = clone.end;
    number = clone.number;
    range = clone.range;
}

/* make 'number' variable in the range */
void CircularInt::normalize(){
    if(number >= start && number <= end)
        return;
    
    while(number > end )
        number -= range;
    while(number < start )
        number += range;
}

CircularInt& CircularInt::operator= (int n){
    number = n;
    normalize();
    return *this;
}

CircularInt CircularInt::operator+ (int n) const{
    CircularInt tmp(*this);
    tmp.number += n;
    tmp.normalize();
    return tmp;
}

/* CircularInt - number
   Example: (CircularInt hour)1 - (int)13 = (CircularInt)12 */
CircularInt CircularInt::operator- (int n) const{
    CircularInt tmp(*this);
    tmp.number -= n;
    tmp.normalize();
    return tmp;
}

CircularInt CircularInt::operator* (int n) const{
    CircularInt tmp(*this);
    tmp.number *= n;
    tmp.normalize();
    return tmp;
}

CircularInt& CircularInt::operator+= (const int n){
    number + n;
    normalize();
    return *this;
}

CircularInt& CircularInt::operator-= (const int n){
    number - n;
    normalize();
    return *this;
}

CircularInt& CircularInt::operator*= (const int n){
    number *= n;
    normalize();
    return *this;
}

/* prefix ++ -> (a)++ */
CircularInt& CircularInt::operator++ (){
    (this->number)++;
    normalize();
    return *this;
}

const CircularInt CircularInt::operator++ (int flag_for_postfix_increment){
    CircularInt tmp(*this); 
    ++(this->number);
    this->normalize();
    return tmp; //returns the copy
    
}

ostream& operator<< (ostream& os, const CircularInt& ci){
    return os << ci.number;
}

