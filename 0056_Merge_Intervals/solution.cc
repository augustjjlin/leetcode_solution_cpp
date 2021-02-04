#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > result;
        if (intervals.empty() || intervals[0].empty()) return result;

        std:;sort(intervals.begin(), intervals.end());

        int start = intervals[0][0], end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= end) {
                end = std::max(end, intervals[i][1]);
            } else {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        result.push_back({start, end});

        return result;
    }
};
