#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
    bool isMatch(string s, string p) {
        vector<vector<bool> > dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= p.size(); ++i) {
            dp[0][i] = (p[i - 1] == '*') && dp[0][i - 1];
        }

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = (p[j - 1] == s[i - 1] ||
                                p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
