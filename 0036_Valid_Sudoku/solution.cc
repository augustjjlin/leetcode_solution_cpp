#include <vector>

class Solution {
 public:
    bool isValidSudoku(std::vector<std::vector<char> >& board) {
        const int M = 9;
        const int N = 9;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (!isValid(M, N, i, j, board)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isValid(
        int M,
        int N,
        int r,
        int c,
        const std::vector<std::vector<char> >& board) {
        char num = board[r][c];

        for (int i = 0; i < M; ++i) {
            if (i == r) {
                continue;
            }

            if (board[i][c] == num) {
                return false;
            }
        }

        for (int j = 0; j < N; ++j) {
            if (j == c) {
                continue;
            }

            if (board[r][j] == num) {
                return false;
            }
        }

        for (int k = 0; k < M; ++k) {
            int current_row = r - r % 3 + k / 3;
            int current_col = c - c % 3 + k % 3;

            if ((current_row == r) && (current_col == c)) {
                continue;
            }

            if (board[current_row][current_col] == num) {
                return false;
            }
        }

        return true;
    }
};
