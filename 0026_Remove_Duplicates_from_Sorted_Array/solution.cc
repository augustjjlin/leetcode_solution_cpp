#include <vector>

using std::vector;

class Solution {
 public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int left = 0, right = 1;

        while (right < nums.size()) {
            if (nums[right] != nums[left]) {
                nums[++left] = nums[right++];
            } else {
                ++right;
            }
        }

        return left + 1;
    }
};
