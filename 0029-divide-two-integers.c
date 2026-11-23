// 29. Divide Two Integers (Medium)
// https://leetcode.com/problems/divide-two-integers/

#include <stdio.h>
#include <limits.h>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    
    int negative = (dividend < 0) ^ (divisor < 0);
    
    long long dvd = dividend;
    long long dvs = divisor;
    if (dvd < 0) dvd = -dvd;
    if (dvs < 0) dvs = -dvs;
    
    long long quotient = 0;
    
    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        quotient += multiple;
    }
    
    return negative ? -quotient : quotient;
}
