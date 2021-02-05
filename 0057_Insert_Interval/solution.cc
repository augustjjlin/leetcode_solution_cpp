#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        bool isInserted = false;
        int start = newInterval[0], end = newInterval[1];

        for (auto i : intervals) {
            if (isInserted) {
                ans.push_back(i);
                continue;
            }

            if (i[1] < start) {
                ans.push_back(i);
            } else if (i[0] > end) {
                ans.push_back({start, end});
                ans.push_back(i);
                isInserted = true;
            } else {
                start = std::min(start, i[0]);
                end = std::max(end, i[1]);
            }
        }

        if (!isInserted) {
            ans.push_back({start, end});
        }

        return ans;
    }
};
