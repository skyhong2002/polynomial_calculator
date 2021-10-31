#include "polynomial.h"
using namespace std;

polynomial::polynomial():size_(0){};
polynomial::polynomial(const polynomial &in){
    for(size_t i = 0; i < in.size_; ++i)
        term_[i] = in.term_[i];
    size_ = in.size_;
}
//polynomial::~polynomial(){}

const int polynomial::term_find(int pow){
    int l = 0;
    int r = size_;
    int m = (l + r)/2;
    while(term_[m].first != pow){
        if(l >= r - 1) return -1;
        if(term_[m].first < pow) r = m;
        else                     l = m + 1;
        m = (l + r)/2;
    }
    return m;
}
polynomial& polynomial::operator+=(const polynomial &rhs){
    for(int i = 0; i < rhs.size_; ++i){
        term_push(rhs.term_[i]);
    }
    return *this;
}
polynomial& polynomial::operator*=(const polynomial &rhs){
    size_t lhs_size_ = size_;
    std::pair<int, int> lhs_term_[100];
    for(int i = 0; i < lhs_size_; ++i)
        lhs_term_[i] = term_[i];
    clear();
    size_ = 0;
    for(int i = 0; i < lhs_size_; ++i){
        for(int j = 0; j < rhs.size_; ++j){
            term_push(lhs_term_[i].first + rhs.term_[j].first,
                      lhs_term_[i].second * rhs.term_[j].second);
        }
    }
    return *this;
}
polynomial& polynomial::operator*=(const int &rhs){
    for(int i = 0; i < size_; ++i){
        term_[i].second *= rhs;
    }
    return *this;
}
polynomial& polynomial::operator=(const polynomial &rhs){
    if(this == &rhs) return *this;
    clear();
    for(size_t i = 0; i < rhs.size_; ++i){
        term_[i] = rhs.term_[i];
    }
    size_ = rhs.size_;
    return *this;
}
void polynomial::term_push(std::pair<int, int> tmp){
    int pos = term_find(tmp.first);
    if(pos != -1){
        if(term_[pos].second - tmp.second == 0){
            term_[pos] = term_[size_-1];
            --size_;
        }
        else{
            term_[pos].second += tmp.second;
        }
    }
    else {
        term_[size_] = tmp;
        ++size_;
    }
    sort(term_, term_ + size_, greater< pair<int, int> >());
    return;
}
void polynomial::term_push(int pow, int coef){
    pair<int, int> tmp;
    tmp.first = pow;
    tmp.second = coef;
    term_push(tmp);
    return;
}
void polynomial::term_edit(int pow, int coef){
    int pos = term_find(pow);
    term_push(pow, coef-term_[pos].second);
}

void polynomial::clear(){
    size_ = 0;
    for(int i = 0; i < 100; ++i)
        term_[i] = make_pair(0, 0);
    return;
}

// A. relational operators (==, !=)
bool operator==(const polynomial &lhs, const polynomial &rhs){
    if(lhs.size() != rhs.size()) return false;
    for(unsigned i = 0; i < lhs.size(); ++i)
        if(lhs.term()[i].first != rhs.term()[i].first ||
           lhs.term()[i].second != rhs.term()[i].second) return false; 
    return true;
}
bool operator!=(const polynomial &lhs, const polynomial &rhs){
    return !(lhs == rhs);
}

// B. operator <<, >>
std::ostream &operator<<(std::ostream &os, const polynomial &out){
    os << "size: " << out.size() << "\n";
    for(int i = 0; i < out.size(); ++i){
        os << out.term()[i].first << " " << out.term()[i].second << "\n";
    }
    return os;
}
std::istream &operator>>(std::istream &is, polynomial &in){
    int size = 0, pow, coef;
    while(size <= 0){
        cout << "How many non-zero item in it? ";
        is >> size;
        if(size <= 0) 
            cout << "Invalid size. Try again.";
    }
    cout << "Excellent. Please key in " << size*2 << " numbers for each power and coefficient.\n"
            "(eg. 3x^2 - 1: 3 2\n"
            "               0 -1)\n";
    for(int i = 0; i < size; ++i){
        coef = 0;
        while(coef == 0){
            is >> pow >> coef;
            if(coef == 0) 
                cout << "Coefficient can't be 0. Try again.\n";
        }
        in.term_push(pow, coef);
    }
    return is;
}

// C. operator +, -, *, /
const polynomial operator+(const polynomial &lhs, const polynomial &rhs){
    polynomial tmp(lhs);
    tmp += rhs;
    return tmp;
}
const polynomial operator-(const polynomial &lhs, const polynomial &rhs){
    polynomial tmp(lhs);
    tmp += (rhs * (-1));
    return tmp;
}
const polynomial operator*(const polynomial &lhs, const polynomial &rhs){
    polynomial tmp(lhs);
    tmp *= rhs;
    return tmp;
}
const polynomial operator*(const polynomial &lhs, const int &rhs){
    polynomial tmp(lhs);
    tmp *= rhs;
    return tmp;
}
const polynomial operator*(const int &lhs, const polynomial &rhs){
    polynomial tmp(rhs);
    tmp *= lhs;
    return tmp;
}
const polynomial operator/(const polynomial &lhs, const polynomial &rhs){
    polynomial tmp(lhs);
    return tmp;
}