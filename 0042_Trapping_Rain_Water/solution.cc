#include <vector>

using std::vector;

class Solution {
 public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int left_max = height[0], right_max = height[height.size() - 1];
        int left = 0, right = height.size() - 1;
        int area = 0;

        while (left <= right) {
            if (left_max <= right_max) {
                left_max = std::max(height[left], left_max);
                area += left_max - height[left];
                ++left;
            } else {
                right_max = std::max(height[right], right_max);
                area += right_max - height[right];
                ++right;
            }
        }

        return area;
    }
};
