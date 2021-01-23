#include <string>

using std::string;

class Solution {
 public:
    string longestPalindrome(string s) {
        int i = 0;
        string result;

        while (i < s.size()) {
            string p_1 = LengthOfPalindrome(s, i, i);
            string p_2 = LengthOfPalindrome(s, i, i + 1);
            p_1 = p_1.size() > p_2.size() ? p_1 : p_2;

            result = result.size() > p_1.size() ? result : p_1;
        }

        return result;
    }

    string LengthOfPalindrome(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }

        return s.substr(left + 1, right - left - 1);
    }
};
