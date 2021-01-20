#include <limits.h>

class Solution {
 public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (x == -1) {
            return (n % 2 == 0) ? 1 : -1;
        }

        if (n < 0) {
            if (n == INT_MIN) {
                return MyPowRecursive(1 / x, INT_MAX) * (1 / x);
            }
            n = -n;
            x = 1 / x;
        }

        return MyPowRecursive(x, n);
    }

    double MyPowRecursive(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;

        if (n % 2 == 0) {
            return MyPowRecursive(x * x, n / 2);
        }

        return MyPowRecursive(x * x, n / 2) * x;
    }
};
