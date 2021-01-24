#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(0, 0, n, ans, "");

        return ans;
    }

    void backtrack(int left, int right, int n, vector<string>& ans, string temp) {
        if (right > left) return;

        if (n == 0) return;

        if (right == n) {
            ans.push_back(temp);
            return;
        }

        if (left < n) {
            temp.push_back('(');
            backtrack(left + 1, right, n, ans, temp);
            temp.pop_back();
        }

        if (right < n) {
            temp.push_back(')');
            backtrack(left, right + 1, n, ans, temp);
            temp.pop_back();
        }
    }
};
