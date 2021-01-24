#include <string>

using std::string;

class Solution {
 public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        bool first_match = !s.empty() &&
                           (p[0] == s[0] ||
                            p[0] == '.');

        if (p.size() >= 2 && p[1] == '*') {
            return (first_match && isMatch(s.substr(1), p)) ||
                   (isMatch(s, p.substr(2)));
        }

        return first_match && isMatch(s.substr(1), p.substr(1));
    }
};
