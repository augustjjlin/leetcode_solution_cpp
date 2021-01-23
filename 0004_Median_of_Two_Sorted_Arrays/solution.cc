#include <vector>

using std::vector;

class Solution {
 public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size(), N = nums2.size();
        int K1 = (M + N) / 2, K2 = (M + N - 1) / 2;

        double result = (FindKInSortedArrays(nums1, 0, nums2, 0, K1) +
            FindKInSortedArrays(nums1, 0, nums2, 0, K2)) / 2.0;

        return result;
    }

    double FindKInSortedArrays(
        const vector<int>& numsA,
        const int& A_left,
        const vector<int>& numsB,
        const int& B_left,
        const int& K) {
        if (A_left >= numsA.size()) return numsB[B_left + K];
        if (B_left >= numsB.size()) return numsA[A_left + K];

        if (K == 0)
            return numsA[A_left] < numsB[B_left] ? numsA[A_left] : numsB[B_left];

        int i = A_left + (K - 1) / 2 < numsA.size() ? A_left + (K - 1) / 2 : numsA.size() - 1;
        int j = B_left + (K - 1) / 2 < numsB.size() ? B_left + (K - 1) / 2 : numsB.size() - 1;

        if (numsA[i] < numsB[j]) {
            return FindKInSortedArrays(numsA, i + 1, numsB, B_left, K - (i - A_left) - 1);
        }

        return FindKInSortedArrays(numsA, A_left, numsB, j + 1, K - (j - B_left) - 1);
    }
};
