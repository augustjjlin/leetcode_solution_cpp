#include <vector>

class Solution {
 public:
    void solveSudoku(std::vector<std::vector<char> >& board) {
        backtrack(9, 9, 0, 0, &board);
    }

    bool backtrack(
        int M,
        int N,
        int r,
        int c,
        std::vector<std::vector<char> >* const board) {
        if (r == M) {
            return true;
        }

        if (c == N) {
            return backtrack(M, N, r + 1, 0, board);
        }

        for (int i = r; i < M; ++i) {
            for (int j = c; j < N; ++j) {
                if ((*board)[i][j] != '.') {
                    return backtrack(M, N, i, j + 1, board);
                }

                for (char k = '1'; k <= '9'; ++k) {
                    if (!isValid(M, N, i, j, k, board)) {
                        continue;
                    }

                    (*board)[i][j] = k;

                    if (backtrack(M, N, i, j + 1, board)) {
                        return true;
                    }

                    (*board)[i][j] = '.';
                }

                return false;
            }
        }
        return false;
    }

    bool isValid(
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
