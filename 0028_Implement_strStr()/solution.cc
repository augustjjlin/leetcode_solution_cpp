#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        if (haystack.empty()) return -1;

        vector<int> next;
        BuildNext(&next, needle);

        int i = 0, j = 0;
        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else if (j != 0) {
                j = next[j - 1];
            } else {
                ++i;
            }
        }

        if (j < needle.size()) return -1;

        return i - j;
    }

    void BuildNext(vector<int>* next, string needle) {
        int next_index = 0;
        next->push_back(next_index);

        int i = 1;
        while (i < needle.size()) {
            if (needle[i] == needle[next_index]) {
                ++next_index;
                ++i;
                next->push_back(next_index);
            } else if (next_index != 0) {
                next_index = next->at(next_index - 1);
            } else {
                ++i;
                next->push_back(next_index);
            }
        }
    }
};
