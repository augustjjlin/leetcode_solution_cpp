#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::pair;

class Solution {
 public:
    vector<vector<int> > permute(vector<int>& nums) {
        if (nums.empty()) return {{}};

        unordered_map<int, int> table;
        for (auto i : nums) {
            if (table.find(i) == table.end()) {
                table.insert(pair<int, int>(i, 0));
            }
            ++table[i];
        }

        vector<vector<int> > ans;
        vector<int> comb;
        Backtrack(nums, &table, &comb, &ans);

        return ans;
    }

    void Backtrack(
        const vector<int>& nums,
        unordered_map<int, int>* table,
        vector<int>* comb,
        vector<vector<int> >* ans) {
        if (comb->size() == nums.size()) {
            ans->push_back(*comb);
            return;
        }

        for (auto i : *table) {
            int current_num = i.first;
            if ((*table)[current_num] == 0) continue;

            comb->push_back(current_num);
            --(*table)[current_num];

            Backtrack(nums, table, comb, ans);

            comb->pop_back();
            ++(*table)[current_num];
        }
    }
};
