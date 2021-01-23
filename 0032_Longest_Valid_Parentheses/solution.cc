#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int result = 0;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = i - 1 > 0 ? dp[i - 2] + 2 : 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            result = std::max(result, dp[i]);
        }
        return result;
    }
};
