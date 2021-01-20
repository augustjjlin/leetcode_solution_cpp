#include <vector>

class Solution {
 public:
    std::vector<std::vector<int> > combinationSum(
        const std::vector<int>& candidates,
        int target) {
        std::vector<std::vector<int> > ans;
        std::vector<int> combination;

        backtrack(candidates, target, &combination, &ans);

        return ans;
    }

    void backtrack(
        const std::vector<int>& candidates,
        int target,
        std::vector<int>* combination,
        std::vector<std::vector<int> >* ans) {
        if (target < 0) return;

        if (target == 0) {
            ans->push_back(*combination);
            return;
        }

        for (auto i : candidates) {
            // 这里选择的值只能大于等于上一次选择的值
            if (!combination->empty()) {
                int last_input = combination->back();
                if (i < last_input) continue;
            }

            combination->push_back(i);
            backtrack(candidates, target - i, combination, ans);
            combination->pop_back();
        }
    }
};
