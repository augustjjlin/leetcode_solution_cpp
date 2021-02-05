#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_set;

class Solution {
 public:
    string getPermutation(int n, int k) {
        string ans("");
        // 用来储存ans中已经存在的数字
        unordered_set<int> container;
        // 用来储存 1, 1!, 2!, ... , n-1!
        vector<int> fac(n, 1);

        // 计算并储存 1, 1!, 2!, ... , n-1!
        int cur = 1;
        for (int i = 1; i < n; ++i) {
            cur *= i;
            fac[i] = cur;
        }

        // 从 n-1! 到 2! , 1!, 1 遍历 fac
        // 对于每一个fac[i], 用此fac[i]来计算ans中第i个数的值
        // 例如第0个数，则fac[i]的值为 n-1!
        // remain的值: 目前剩余的数字中，第remain个数就是ans中第i个数的值
        // remain求出来是index
        for (int i = fac.size() - 1; i >= 0; --i) {
            int cur_fac = fac[i];
            int remain = (k - 1) / cur_fac;
            int count = 0;
            int j = 1;
            while (count <= remain) {
                if (container.find(j) != container.end()) {
                    ++j;
                } else {
                    if (count == remain) {
                        ans.push_back(j + '0');
                        container.insert(j);
                        break;
                    } else {
                        ++count;
                        ++j;
                    }
                }
            }
            k = k - remain * cur_fac;
        }

        return ans;
    }
};
