#include <vector>
#include <climits>

using std::vector;

class Solution {
 public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;

        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0, count = 0;
        // 0: right, 1: down, 2: left, 3: up
        int direction = 0;

        while (count < m * n) {
            result.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            ++count;

            if (direction == 0) {
                if (j + 1 == n || matrix[i][j + 1] == INT_MIN) {
                    ++direction;
                    ++i;
                } else {
                    ++j;
                }
            } else if (direction == 1) {
                if (i + 1 == m || matrix[i + 1][j] == INT_MIN) {
                    ++direction;
                    --j;
                } else {
                    ++i;
                }
            } else if (direction == 2) {
                if (j == 0 || matrix[i][j - 1] == INT_MIN) {
                    ++direction;
                    --i;
                } else {
                    --j;
                }
            } else if (direction == 3) {
                if (i == 0 || matrix[i - 1][j] == INT_MIN) {
                    direction = 0;
                    ++j;
                } else {
                    --i;
                }
            }
        }

        return result;
    }
};
