# Polynomial Calculator
NTNU CSIE 41047033S 洪軾凱
Data Structure HW3

```
g++ --std=c++14 main.cpp polynomial.cpp
./a.out
```

GitHub: https://github.com/skyhong2002/polynomial_calculator

## Guide

1 to key in a polynomial.<br>
2 to show the whole polynomial.<br>
3 to show the particular coefficent of the polynomial.<br>
4 to edit the particular Non-zero item of the polynomial.<br>
5 to do the add+tion.<br>
6 to do the subtra-tion.<br>
7 to do the multipl*cation.<br>
8 to do the d/vision.(Not supported in this version)<br>
9 to list all the polynomial created.<br>
0 to exit.<br>
Don't forget to press the return butten owo<br>

## Complexity analysis

### Build/Edit a polynomial
push: O(n)/O(1)<br>
sort: O(n log n)/O(n)<br>
total complexity: O(n log n)/O(n)

### Arithmetic
#### add+tion, subtra-tion
push: O(n)<br>
sort: O(n log n)<br>
total complexity: O(n log n)
#### multipl*cation
push: O(n^2)<br>
sort: O(n log n)<br>
total complexity: O(n^2)
