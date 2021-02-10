#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
    int numDecodings(string s) {
        if (s.empty()) return 0;

        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for (int i = 2; i < dp.size(); ++i) {
            int cur_digit = s[i - 1] - '0';
            int two_digits = (s[i - 2] - '0') * 10 + cur_digit;
            
            
            if (cur_digit >= 1 && cur_digit <= 9) {
                dp[i] += dp[i - 1];
            }

            if (two_digits >= 10 && two_digits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.size()];
    }
};
