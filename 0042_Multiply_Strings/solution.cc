#include <string>
#include <vector>

using std::string;
using std::vector;

//     1 2 3
//     4 5 6
// ---------
//       1 8
//     1 2
//     6
//     1 5
//   1 0
//   5
//   1 2
//   8
// 4
// ---------

class Solution {
 public:
    string multiply(string num1, string num2) {
        // Vector to save the result
        vector<int> res(num1.size() + num2.size(), 0);

        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                int digit_1 = num1[i] - '0';
                int digit_2 = num2[j] - '0';
                int prod = digit_1 * digit_2;

                int position_1 = i + j, position_2 = i + j + 1;
                int sum = prod + res[position_2];
                res[position_2] = sum % 10;
                res[position_1] += sum / 10;
            }
        }

        int first_not_zero_index = 0;
        while (first_not_zero_index < res.size() && res[first_not_zero_index] == 0) {
            ++first_not_zero_index;
        }

        string result;
        while (first_not_zero_index < res.size()) {
            result.push_back('0' + res[first_not_zero_index]);
            ++first_not_zero_index;
        }

        return result.empty() ? "0" : result;
    }
};
