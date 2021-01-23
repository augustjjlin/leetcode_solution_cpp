#include <string>
#include <climits>

using std::string;

class Solution {
 public:
    int myAtoi(string s) {
        int result = 0;
        int sign = 1;
        int i = 0;

        while (i < s.size() && s[i] == ' ') {
            ++i;
        }

        if (s[i] == '+' || s[i] == '-') {
            sign = s[i++] == '-' ? -1 : 1;
        }

        while (i < s.size() &&
            s[i] <= '9' &&
            s[i] >= '0') {
            int digit = (s[i++] - '0');

            if (result > (INT_MAX / 10) ||
                (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign > 0 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
        }

        return result * sign;
    }
};
