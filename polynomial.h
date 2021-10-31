#ifndef polynomial__
#define polynomial__
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

class polynomial{
public:
    polynomial();
    polynomial(const polynomial &in);
    //~polynomial();
    const std::pair<int, int>* term() const { return term_; }
    const size_t size() const { return size_; }
    const int term_find(int pow);
    polynomial &operator+=(const polynomial &rhs);
    polynomial &operator*=(const polynomial &rhs);
    polynomial &operator*=(const int &rhs);
    polynomial &operator=(const polynomial &rhs);
    void term_push(std::pair<int, int> tmp);
    void term_push(int pow, int coef);
    void term_edit(int pow, int coef);
    void clear();
private:
    size_t size_;
    std::pair<int, int> term_[100];
};

// A. relational operators (==, !=)
bool operator==(const polynomial &lhs, const polynomial &rhs);
bool operator!=(const polynomial &lhs, const polynomial &rhs);

// B. operator <<, >>
std::ostream &operator<<(std::ostream &os, const polynomial &out);
std::istream &operator>>(std::istream &is, polynomial &in);

// C. operator +, -, *, /
const polynomial operator+(const polynomial &lhs, const polynomial &rhs);
const polynomial operator-(const polynomial &lhs, const polynomial &rhs);
const polynomial operator*(const polynomial &lhs, const polynomial &rhs);
const polynomial operator*(const polynomial &lhs, const int &rhs);
const polynomial operator*(const int &lhs, const polynomial &rhs);
const polynomial operator/(const polynomial &lhs, const polynomial &rhs);


#endif