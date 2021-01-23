#include <climits>

class Solution {
 public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        int result = 0;

        while (x != 0) {
            int digit = x % 10;

            if (result > 0 &&
                (result > INT_MAX / 10 ||
                    (result == INT_MAX / 10 && digit > INT_MAX % 10))) {
                return 0;
            }

            if (result < 0 &&
                (result < INT_MIN / 10 ||
                    (result == INT_MIN / 10 && digit < INT_MIN % 10))) {
                return 0;
            }

            result = result * 10 + digit;
            x /= 10;
        }

        return result;
    }
};
