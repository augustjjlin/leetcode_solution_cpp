#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
    int totalNQueens(int n) {
        if (n == 0) return 0;

        vector<int> has_col(n, 0);
        vector<int> has_ldiag(2 * n - 1, 0);
        vector<int> has_rdiag(2 * n - 1, 0);

        return BackTrack(n, 0, &has_col, &has_ldiag, &has_rdiag);
    }

    int BackTrack(
        int n,
        int row,
        vector<int>* has_col,
        vector<int>* has_ldiag,
        vector<int>* has_rdiag) {
        if (row == n) {
            return 1;
        }

        int sub_result = 0;

        for (int i = 0; i < n; ++i) {
            if (has_col->at(i) == 1 ||
                has_ldiag->at(n - 1 - row + i) == 1 ||
                has_rdiag->at(row + i) == 1) {
                continue;
            }

            has_col->at(i) = 1;
            has_ldiag->at(n - 1 - row + i) = 1;
            has_rdiag->at(row + i) = 1;

            sub_result += BackTrack(n, row + 1, has_col, has_ldiag, has_rdiag);

            has_col->at(i) = 0;
            has_ldiag->at(n - 1 - row + i) = 0;
            has_rdiag->at(row + i) = 0;
        }

        return sub_result;
    }
};
