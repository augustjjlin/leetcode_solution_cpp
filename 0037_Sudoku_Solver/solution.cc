#include <vector>

class Solution {
 public:
    void solveSudoku(std::vector<std::vector<char> >& board) {
        BackTrack(9, 9, 0, 0, &board);
    }

    bool BackTrack(
        int M,
        int N,
        int r,
        int c,
        std::vector<std::vector<char> >* const board) {
        if (r == M) {
            return true;
        }

        if (c == N) {
            return BackTrack(M, N, r + 1, 0, board);
        }

        if ((*board)[r][c] != '.') {
            return BackTrack(M, N, r, c + 1, board);
        }

        for (char k = '1'; k <= '9'; ++k) {
            if (!IsValid(M, N, r, c, k, board)) {
                continue;
            }

            (*board)[r][c] = k;

            if (BackTrack(M, N, r, c + 1, board)) {
                return true;
            }

            (*board)[r][c] = '.';
        }

        return false;
    }

    bool IsValid(
        int M,
        int N,
        int r,
        int c,
        char num,
        const std::vector<std::vector<char> >* const board) {
        for (int i = 0; i < M; ++i) {
            if ((*board)[i][c] == num) {
                return false;
            }
        }

        for (int j = 0; j < N; ++j) {
            if ((*board)[r][j] == num) {
                return false;
            }
        }

        for (int k = 0; k < M; ++k) {
            if ((*board)[r - r % 3 + k / 3][c - c % 3 + k % 3] == num) {
                return false;
            }
        }

        return true;
    }
};
