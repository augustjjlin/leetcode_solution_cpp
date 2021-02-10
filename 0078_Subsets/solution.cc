#include <vector>

using std::vector;

class Solution {
 public:
    vector<vector<int> > subsets(const vector<int>& nums) {
        vector<vector<int> > ans(1, vector<int>());

        for (auto i : nums) {
            int current_size = ans.size();
            for (int j = 0; j < current_size; ++j) {
                vector<int> cur_sub = ans[j];
                cur_sub.push_back(i);
                ans.push_back(cur_sub);
            }
        }

        return ans;
    }
};
