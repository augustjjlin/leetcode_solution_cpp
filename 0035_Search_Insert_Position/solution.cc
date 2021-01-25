#include <vector>

using std::vector;

class Solution {
 public:
    int searchInsert(vector<int>& nums, int target) {
        return LowerBound(nums, target);
    }

    int LowerBound(const vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid = 0;

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

        return left;
    }
};
