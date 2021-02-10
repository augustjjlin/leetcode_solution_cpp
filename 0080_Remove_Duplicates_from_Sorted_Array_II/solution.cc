#include <vector>

using std::vector;

class Solution {
 public:
    int removeDuplicates(vector<int>& nums) {
        int slow = -1, fast = 0;
        int count = 0;
        while (fast < nums.size()) {
            if (slow == -1) {
                nums[++slow] = nums[fast];
                ++count;
            } else if (nums[fast] == nums[slow]) {
                if (count < 2) {
                    nums[++slow] = nums[fast];
                    ++count;
                }
            } else {
                count = 1;
                nums[++slow] = nums[fast];
            }
            ++fast;
        }

        return slow + 1;
    }
};
