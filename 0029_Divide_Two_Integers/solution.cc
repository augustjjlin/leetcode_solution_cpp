#include <climits>

class Solution {
 public:
    int divide(int dividend, int divisor) {
        // Base Case
        if (dividend == 0 || divisor == 1) {
            return dividend;
        }

        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;

            return -dividend;
        }

        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) return 1;

            return 0;
        }

        int sign = (dividend ^ divisor) < 0 ? -1 : 1;

        // Make the sign of divisor and dividend both < 0
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        int count = 1, temp = divisor;
        while (temp > dividend &&
            (INT_MIN >> 1) < temp &&
            temp * 2 >= dividend) {
            temp *= 2;
            count *= 2;
        }

        while (temp > dividend &&
            (INT_MIN - divisor) <= temp &&
            temp + divisor >= dividend) {
            temp += divisor;
            count += 1;
        }

        if (temp >= dividend) return count * sign;

        return 0;
    }
};
