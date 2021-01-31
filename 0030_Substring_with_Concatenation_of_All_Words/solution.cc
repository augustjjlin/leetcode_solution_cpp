#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
 public:
    vector<int> findSubstring(string s, const vector<string>& words) {
        vector<int> result;
        unordered_map<string, int> count_word;

        for (auto s : words) {
            if (count_word.find(s) == count_word.end()) {
                count_word.insert(std::make_pair(s, 0));
            }

            ++count_word[s];
        }

        int N = s.size(), num = words.size(), num_len = words[0].size();
        for (int i = 0; i < N - num * num_len + 1; ++i) {
            unordered_map<string, int> count_exist;
            int j = 0;

            while (j < num) {
                string word = s.substr(i + j * num_len, num_len);
                if (count_word.find(word) != count_word.end()) {
                    if (count_exist.find(word) == count_exist.end()) {
                        count_exist.insert(std::make_pair(word, 0));
                    }
                    ++count_exist[word];

                    if (count_exist[word] <= count_word[word]) {
                        ++j;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }

            if (j == num) {
                result.push_back(i);
            }
        }

        return result;
    }
};
