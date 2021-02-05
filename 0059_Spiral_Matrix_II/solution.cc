#include <vector>

using std::vector;

class Solution {
 public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n, 0));

        int count = 1;
        int i = 0, j = 0;
        // 0: right, 1: down, 2: left, 3: up
        int direction = 0;

        while (count <= n * n) {
            ans[i][j] = count;
            ++count;

            if (direction == 0) {
                if (j + 1 == n || ans[i][j + 1] != 0) {
                    ++i;
                    ++direction;
                } else {
                    ++j;
                }
            } else if (direction == 1) {
                if (i + 1 == n || ans[i + 1][j] != 0) {
                    --j;
                    ++direction;
                } else {
                    ++i;
                }
            } else if (direction == 2) {
                if (j == 0 || ans[i][j - 1] != 0) {
                    --i;
                    ++direction;
                } else {
                    --j;
                }
            } else {
                if (i == 0 || ans[i - 1][j] != 0) {
                    ++j;
                    direction = 0;
                } else {
                    --i;
                }
            }
        }

        return ans;
    }
};
