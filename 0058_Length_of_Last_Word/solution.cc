#include <string>
#include <sstream>

using std::string;
using std::stringstream;

class Solution {
 public:
    int lengthOfLastWord(string s) {
        int length = 0;
        stringstream ss(s);
        string token;

        while (std::getline(ss, token, ' ')) {
            if (token.size() == 0) continue;

            length = token.size();
        }

        return length;
    }
};
