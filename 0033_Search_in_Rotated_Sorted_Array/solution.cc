#include <vector>

class Solution {
 public:
    int search(const std::vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int start = 0, end = nums.size() - 1, mid;

        while (start <= end) {
            mid = (start + end) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[start] == nums[mid]) {
                ++start;
            } else if (nums[mid] <= nums[end]) {
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if (nums[mid] > target && target >= nums[start]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }

        return -1;
    }
};
