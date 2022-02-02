class Solution {
public:
    int divide(int x, int y) {
           //extraction of sign
    int sign = ((x < 0) ^ (y < 0)) ? -1 : +1;

    long int q = 0;

    long long int div = y;
    long long int dividend = x;

    dividend = abs(dividend);
    div = abs(div);

    for (int i = 31; i >= 0; i--) {

        if ( (div << i)  <= dividend) {
            q = q | (1LL << i);
            dividend = dividend - (div << i);
        }

        if (dividend < div)
            break;
    }


    q = sign * q;
    if (q < INT_MIN)
        return INT_MIN;

    if (q > INT_MAX)
        return INT_MAX;

    return q;
    }
};