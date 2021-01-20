#include <vector>
#include <string>
#include <unordered_map>

class Solution {
 public:
    bool isSubsequence(std::string s, std::string t) {
        std::unordered_map<char, std::vector<int> > char_index;

        for (int i = 0; i < t.size(); ++i) {
            const char& ch = t[i];
            if (char_index.find(ch) == char_index.end()) {
                char_index[ch] = std::vector<int>{i};
            } else {
                char_index[ch].push_back(i);
            }
        }

        int j = 0;

        for (const char& ch_s : s) {
            if (char_index.find(ch_s) == char_index.end()) {
                return false;
            } else {
                j = LowerBound(char_index[ch_s], j);

                if (j == -1) return false;
            }
        }

        return true;
    }

    // 二分查找左侧边界，如果数组数字都比target小，返回 -1
    int LowerBound(const std::vector<int>& index_list, int target) {
        int left = 0, right = index_list.size(), mid;

        while (left < right) {
            mid = (left + right) / 2;
            if (index_list[mid] == target) {
                right = mid;
            } else if (index_list[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // +1 是因为如果找到了，需要向后进一位，不然对于重复字符，j永远不会变。
        return left == index_list.size() ? -1 : index_list[left] + 1;
    }
};
