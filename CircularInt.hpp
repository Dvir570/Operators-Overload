#include <iostream>
using namespace std;

class CircularInt{
    private:
        int start, end, number, range;
        
        CircularInt(const CircularInt& clone);
        
        /* make this->number in the range */
        void normalize();
        
    public:
        CircularInt(int x, int y);
        
        int getNumber();
        CircularInt& operator= (int n);
        CircularInt operator+ (int n) const;
        CircularInt operator+ (const CircularInt& ci) const;
        CircularInt operator- (int n) const;
        CircularInt operator* (int n) const;
        CircularInt operator/ (int n) const;
        CircularInt& operator+= (const int n);
        CircularInt& operator-= (const int n);
        CircularInt& operator*= (const int n);
        CircularInt& operator/= (const int n);
        CircularInt& operator++ (); //prefix ++ -> ++(a)
        const CircularInt operator++ (int flag_for_postfix_increment); //postfix ++ -> (a)++ 
        const CircularInt operator- () const;
        friend CircularInt operator- (int n, const CircularInt& ci);
        friend ostream& operator<< (ostream& os, const CircularInt& ci);
        //friend istream& operator>> (istream& is, Complex& c);
        
        
};