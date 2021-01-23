#include <vector>

using std::vector;

class Solution {
 public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        return NSum(nums, 4, 0, target);
    }

    vector<vector<int> > NSum(
        const vector<int>& nums,
        int N,
        int start,
        int target) {
        vector<vector<int> > res;

        if (N < 2 || nums.size() - start < N) return res;

        if (N == 2) {
            int left = start, right = nums.size() - 1;

            while (left < right) {
                int lo = nums[left], hi = nums[right];

                if (lo + hi < target) {
                    ++left;
                } else if (lo + hi > target) {
                    --right;
                } else {
                    res.push_back(vector<int>{nums[left], nums[right]});
                    while (left < nums.size() && nums[left] == lo) ++left;
                    while (right >= 0 && nums[right] == hi) --right;
                }
            }
        } else {
            for (int i = start; i < nums.size(); ++i) {
                vector<vector<int> > sub = NSum(nums, N - 1, i + 1, target - nums[i]);
                for (auto &arr : sub) {
                    arr.push_back(nums[i]);
                    res.push_back(arr);
                }
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
            }
        }

        return res;
    }
};