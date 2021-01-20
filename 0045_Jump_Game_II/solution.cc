#include <vector>
#include <algorithm>

class Solution {
 public:
    int jump(const std::vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return 0;

        // Times of jump
        int jumps = 0;
        // Maximum end index from current position
        int end = 0;
        // Fartest index from current position to end can jump
        int farthest = 0;

        // Exclude the last position
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Get the fartest position from [current, end]
            farthest = std::max(i + nums[i], farthest);
            if (i == end) {
                // Jump to the interval [current, fartest]
                end = farthest;
                ++jumps;
            }
        }

        return jumps;
    }
};
