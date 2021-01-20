#include <vector>
#include <unordered_map>

class Solution {
 public:
    std::vector<std::vector<int> > combinationSum2(
        std::vector<int>& candidates,
        int target) {
        std::vector<std::vector<int> > ans;
        std::vector<int> combination;

        std::unordered_map<int, int> candidate_count;

        // 先对candidates进行计数
        for (auto i : candidates) {
            ++candidate_count[i];
        }

        // 回溯
        backtrack(candidates, target, &candidate_count, &combination, &ans);

        return ans;
    }

    void backtrack(
        const std::vector<int>& candidates,
        int target,
        std::unordered_map<int, int>* candidate_count,
        std::vector<int>* combination,
        std::vector<std::vector<int> >* ans) {
        if (target < 0) return;

        if (target == 0) {
            ans->push_back(*combination);
            return;
        }

        // 对unique的数进行遍历
        for (auto &i : *candidate_count) {
            // 如果该数已经被选完了，则跳过
            if (i.second == 0) continue;

            // 如果该数比上一次选择的小，则跳过
            if (!combination->empty()) {
                if (i.first < combination->back()) continue;
            }

            --(i.second);
            combination->push_back(i.first);

            backtrack(candidates, target - i.first, candidate_count, combination, ans);

            ++(i.second);
            combination->pop_back();
        }
    }
};
