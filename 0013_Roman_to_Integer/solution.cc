#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
 public:
    int romanToInt(string s) {
        unordered_map<char, int> symbol_value_table({
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        });

        int result = 0;
        int prev = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            int value_i = symbol_value_table[s[i]];

            if (prev <= value_i) {
                result += value_i;
            } else {
                result -= value_i;
            }

            prev = value_i;
        }

        return result;
    }
};
