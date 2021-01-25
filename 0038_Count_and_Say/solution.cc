#include <string>

using std::string;

class Solution {
 public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string to_say = countAndSay(n - 1);

        int count = 1;
        string result;
        for (int i = 1; i < to_say.size(); ++i) {
            if (to_say[i] != to_say[i - 1]) {
                result += std::to_string(count);
                result.push_back(to_say[i - 1]);
                count = 1;
            } else {
                ++count;
            }
        }

        result += std::to_string(count);
        result.push_back(to_say[to_say.size() - 1]);

        return result;
    }
};
