#include <vector>
#include <map>

class Solution {
 public:
    void nextPermutation(std::vector<int>& nums) {
        // 找到第一个比右侧小的数
        int i = nums.size() - 2;

        while (i >= 0 && nums[i + 1] <= nums[i]) {
            --i;
        }

        if (i >= 0) {
            // 从右边往左找到第一个比nums[i]大的数
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                --j;
            }

            // 交换
            std::swap(nums[i], nums[j]);
        }

        std::reverse(nums.begin() + 1 + i, nums.end());
    }
};
