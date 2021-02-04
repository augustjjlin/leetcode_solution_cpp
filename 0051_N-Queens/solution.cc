#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        if (n == 0) return result;

        vector<string> board(n, string(n, '.'));
        vector<int> has_col(n, 0);
        vector<int> has_ldiag(2 * n - 1, 0);
        vector<int> has_rdiag(2 * n - 1, 0);

        BackTrack(n, 0, &has_col, &has_ldiag, &has_rdiag, &board, &result);

        return result;
    }

    void BackTrack(
        int n,
        int row,
        vector<int>* has_col,
        vector<int>* has_ldiag,
        vector<int>* has_rdiag,
        vector<string>* board,
        vector<vector<string> >* result) {
        if (row == n) {
            result->push_back(*board);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (has_col->at(i) == 1 ||
                has_ldiag->at(n - 1 - row + i) == 1 ||
                has_rdiag->at(row + i) == 1) {
                continue;
            }

            has_col->at(i) = 1;
            has_ldiag->at(n - 1 - row + i) = 1;
            has_rdiag->at(row + i) = 1;
            board->at(row).at(i) = 'Q';

            BackTrack(n, row + 1, has_col, has_ldiag, has_rdiag, board, result);

            has_col->at(i) = 0;
            has_ldiag->at(n - 1 - row + i) = 0;
            has_rdiag->at(row + i) = 0;
            board->at(row).at(i) = '.';
        }
    }
};
