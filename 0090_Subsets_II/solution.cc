#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;

class Solution {
 public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans(1, vector<int>()); 
        unordered_map<int, vector<vector<int> > > collect;

        std::sort(nums.begin(), nums.end());

        for (auto i : nums) {
            if (collect.find(i) == collect.end()) {
                vector<vector<int> > collect_i;
                int current_size = ans.size();
                for (int j = 0; j < current_size; ++j) {
                    vector<int> cur = ans[j];
                    cur.push_back(i);
                    collect_i.push_back(cur);
                    ans.push_back(cur);
                }
                collect.insert(make_pair(i, collect_i));
            } else {
                for (auto& cur_collect : collect[i]) {
                    cur_collect.push_back(i);
                    ans.push_back(cur_collect);
                }
            }
        }

        return ans;
    }
};
