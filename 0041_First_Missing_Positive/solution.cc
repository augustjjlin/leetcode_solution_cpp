#include <vector>

using std::vector;

class Solution {
 public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();

        for (int i = 0; i < N; ++i) {
            if (nums[i] <= 0) {
                nums[i] = N + 1;
            }
        }

        for (int i = 0; i < N; ++i) {
            if (nums[i] > N) {
                nums[i] = N + 1;
            }
        }

        for (int i = 0; i < N; ++i) {
            if (nums[i] < 0) {
                if (-nums[i] < N + 1) {
                    if (nums[-nums[i] - 1] > 0) {
                        nums[-nums[i] - 1] = -nums[-nums[i] - 1];
                    }
                }
            } else if (nums[i] > N) {
                continue;
            } else {
                if (nums[nums[i] - 1] > 0) {
                    nums[nums[i] - 1] = -nums[nums[i] - 1];
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return N + 1;
    }
};
