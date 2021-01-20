#include <limits.h>
#include <vector>
#include <algorithm>

class Solution {
 public:
    int maxSubArray(const std::vector<int>& nums) {
        if (nums.empty()) return INT_MIN;

        int sub_max = nums[0], max_value = nums[0];

        // Dynamic Programming
        // dp[i] = max(dp[i - 1] + nums[i], nums[i])
        // max value = max(dp)
        for (int i = 1; i < nums.size(); ++i) {
            sub_max = std::max(sub_max + nums[i], nums[i]);
            max_value = std::max(max_value, sub_max);
        }

        return max_value;
    }
};
