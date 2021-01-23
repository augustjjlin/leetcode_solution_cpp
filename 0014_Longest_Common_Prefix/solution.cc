#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
    string longestCommonPrefix(const vector<string>& strs) {
        if (strs.empty()) return "";

        string result = strs.front();

        for (int i = 1; i < strs.size(); ++i) {
            result = GetCommonPrefix(result, strs[i]);
        }

        return result;
    }

    string GetCommonPrefix(string s1, string s2) {
        int i = 0, j = 0;
        string result = "";

        while (i < s1.size() && j < s2.size()) {
            if (s1[i] != s2[j]) break;
            result += s1[i];
            ++i;
            ++j;
        }

        return result;
    }
};
