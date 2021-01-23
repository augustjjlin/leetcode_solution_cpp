#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> zigzag(numRows, "");
        bool add = true;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            zigzag[count].push_back(s[i]);

            if (count == 0) add = true;
            if (count == numRows - 1) add = false;

            if (add) {
                ++count;
            } else {
                --count;
            }
        }

        string result;
        for (auto temp_s : zigzag) {
            result += temp_s;
        }

        return result;
    }
};
