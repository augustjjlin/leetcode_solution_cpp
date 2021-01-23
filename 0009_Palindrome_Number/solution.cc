#include <climits>

class Solution {
 public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x >= 0 && x < 10) return true;
        if (x % 10 == 0) return false;

        int comp = 0;
        int y = x;
        while (x != 0) {
            int digit = x % 10;

            if (comp > INT_MAX / 10 ||
                (comp == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return 0;
            }

            comp = comp * 10 + digit;
            x /= 10;

            if (comp == x) return true;
        }

        return comp == y;
    }
};
