#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
 public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ch_index_table;
        int left = 0, right = 0, max_len = 0;

        while (right < s.size()) {
            char ch = s[right];

            if (ch_index_table.find(ch) == ch_index_table.end()) {
                ch_index_table[ch] = right;
            } else {
                if (left <= ch_index_table[ch]) {
                    left = ch_index_table[ch] + 1;
                }
                ch_index_table[ch] = right;
            }
            max_len = std::max(max_len, right - left + 1);
            ++right;
        }

        return max_len;
    }
};
