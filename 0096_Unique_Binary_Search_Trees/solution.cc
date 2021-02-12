#include <vector>

using std::vector;

class Solution {
 public:
    int numTrees(int n) {
        vector<int> num_map(n + 1, -1);
        num_map[0] = num_map[1] = 1;

        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result += GetCount(i - 1, &num_map) * GetCount(n - i, &num_map);
        }

        return result;
    }

    int GetCount(int n, vector<int>* num_map) {
        if (num_map->at(n) != -1) return num_map->at(n);

        int current_count = 0;
        for (int i = 1; i <= n; ++i) {
            current_count += GetCount(i - 1, num_map) * GetCount(n - i, num_map);
        }

        num_map->at(n) = current_count;
        return current_count;
    }
};
