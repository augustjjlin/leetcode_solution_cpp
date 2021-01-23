#include <vector>
#include <cmath>
#include <climits>

using std::vector;

class Solution {
 public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target - sum) < abs(diff)) diff = target - sum;
                if (diff == 0) return target;
                if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return target - diff;
    }
};
