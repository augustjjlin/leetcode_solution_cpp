#include <vector>

class Solution {
 public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        return std::vector<int> {
            lower_bound(nums, target),
            upper_bound(nums, target)};
    }

    int lower_bound(const std::vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid;

        while (left < right) {
            mid = (left + right) / 2;

            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left == nums.size()) return -1;

        return nums[left] == target ? left : -1;
    }

    int upper_bound(const std::vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid;

        while (left < right) {
            mid = (left + right) / 2;

            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left == 0) return -1;

        return nums[left - 1] == target ? (left - 1) : -1;
    }
};
