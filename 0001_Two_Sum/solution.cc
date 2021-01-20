#include <vector>
#include <unordered_map>

class Solution {
 public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> index_num;

        for (int i = 0; i < nums.size(); ++i) {
            int expect_num = target - nums[i];

            if (index_num.find(expect_num) != index_num.end()) {
                return std::vector<int>{i, index_num[expect_num]};
            }

            index_num.insert(std::make_pair(nums[i], i));
        }

        return std::vector<int>{-1, -1};
    }
};
