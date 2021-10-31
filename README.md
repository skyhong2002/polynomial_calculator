# Polynomial Calculator
NTNU CSIE 41047033S 洪軾凱
Data Structure HW3

```
g++ --std=c++14 main.cpp polynomial.cpp
./a.out
```

GitHub: https://github.com/skyhong2002/polynomial_calculator

## Guide

1 to key in a polynomial.
2 to show the whole polynomial.
3 to show the particular coefficent of the polynomial.
4 to edit the particular Non-zero item of the polynomial.
5 to do the add+tion.
6 to do the subtra-tion.
7 to do the multipl*cation.
8 to do the d/vision.(Not supported in this version)
9 to list all the polynomial created.
0 to exit.
Don't forget to press the return butten owo

## Complexity analysis

### Build a polynomial
push: O(n)
sort: O(n log n)
total complexity: O(n log n)

### Edit a polynomial
push: O(1)
sort: O(n) (worst case)
total complexity: O(n)

### Arithmetic
#### add+tion, subtra-tion
push: O(n)
sort: O(n log n)
total complexity: O(n log n)
#### multipl*cation
push: O(n^2)
sort: O(n log n)
total complexity: O(n^2)