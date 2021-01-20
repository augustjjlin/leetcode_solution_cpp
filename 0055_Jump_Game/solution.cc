#include <vector>
#include <algorithm>

class Solution {
 public:
    bool canJump(const std::vector<int>& nums) {
        if (nums.empty()) return true;

        // Farthest position you can jump
        int farthest = 0;

        // Exclude the last position
        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);

            // If can jump far away last position, return true;
            if (farthest >= (nums.size() - 1)) return true;

            // If it can't jump anymore from current position, return false;
            if (farthest <= i) return false;
        }

        return farthest >= (nums.size() - 1) ? true : false;
    }
};
