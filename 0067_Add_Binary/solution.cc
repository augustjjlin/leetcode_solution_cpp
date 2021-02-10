#include <string>
#include <algorithm>

using std::string;

class Solution {
 public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string result("");

        while (i >= 0 || j >= 0 || carry == 1) {
            int a_digit = i < 0 ? 0 : a[i] - '0';
            int b_digit = j < 0 ? 0 : b[j] - '0';

            int current_digit = (a_digit + b_digit + carry) % 2;
            carry = (a_digit + b_digit + carry) / 2;

            result = string(1, current_digit + '0') + result;

            --i;
            --j;
        }

        return result;
    }
};
