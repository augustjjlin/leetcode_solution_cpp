#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
    vector<string> letterCombinations(string digits) {
        vector<string> table{
            "", "", "abc",
            "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"};

        vector<string> result;
        backtrack(digits, 0, table, result, "");

        return result;
    }

    void backtrack(const string& digits, int level,
        const vector<string>& table, vector<string>& result, string temp) {
        if (level == digits.size()) {
            if (level == 0) return;

            result.push_back(temp);
            return;
        }

        int digit = digits[level] - '0';
        string cur_map = table[digit];

        for (auto ch : cur_map) {
            temp.push_back(ch);
            backtrack(digits, level + 1, table, result, temp);
            temp.pop_back();
        }
    }
};

