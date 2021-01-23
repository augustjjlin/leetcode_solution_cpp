#include <vector>

using std::vector;

class Solution {
 public:
    int maxArea(const vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while (left <= right) {
            max_area = std::max(max_area,
                std::min(height[left], height[right]) * (right - left));

            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return max_area;
    }
};
