#include<iostream>
using namespace std;
int divide(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    long long a = abs((long long)dividend);
    long long b = abs((long long)divisor);
    long long quotient = 0;
    while (a >= b) {
        a -= b;
        quotient++;
    }
    if ((dividend < 0) ^ (divisor < 0))
        quotient = -quotient;
    return (int)quotient;
}
