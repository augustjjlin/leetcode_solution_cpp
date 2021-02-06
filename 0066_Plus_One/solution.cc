#include <vector>

using std::vector;

class Solution {
 public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (carry == 1) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                    if (i == 0) {
                        digits.insert(digits.begin(), 1);
                    }
                } else {
                    ++digits[i];
                    carry = 0;
                }
            }
        }

        return digits;
    }
};
