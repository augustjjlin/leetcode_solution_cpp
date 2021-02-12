#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<vector<int> > constrain{{0, 9}, {10, 99}, {100, 255}};
        BackTrack(s, constrain, 0, "", &result);

        return result;
    }

    void BackTrack(
        string s,
        const vector<vector<int> >& constrain,
        int count,
        string temp,
        vector<string>* result) {
        if (count == 4) {
            if (s.empty()) result->push_back(temp.substr(0, temp.size() - 1));

            return;
        }

        int current_value = 0;
        for (int i = 0; i < s.size() && i < 3; ++i) {
            current_value = current_value * 10 + (s[i] - '0');

            if (current_value >= constrain[i][0] &&
                current_value <= constrain[i][1]) {
                string current_part = std::to_string(current_value) + ".";
                temp += current_part;
                BackTrack(s.substr(i + 1), constrain, count + 1, temp, result);
                temp = temp.substr(0, temp.size() - current_part.size());
            }
        }
    }
};
