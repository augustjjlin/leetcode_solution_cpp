#include <string>
#include <vector>
#include <unordered_map>

class Solution {
 public:
    std::vector<std::vector<std::string> > groupAnagrams(const std::vector<std::string>& strs) {
        std::vector<std::vector<std::string> > ans;
        std::unordered_map<std::string, std::vector<std::string> > anagrams_group;

        for (auto s : strs) {
            std::vector<int> char_count(26);

            for (auto ch : s) {
                ++char_count[ch - 'a'];
            }

            std::string key_of_group;
            for (int i = 0; i < char_count.size(); ++i) {
                if (char_count[i] > 0) {
                    char ch = (i + 'a');
                    key_of_group += std::to_string(char_count[i]);
                    key_of_group += ch;
                }
            }

            anagrams_group[key_of_group].push_back(s);
        }

        for (auto i = anagrams_group.begin();
            i != anagrams_group.end();
            ++i) {
            ans.push_back(i->second);
        }

        return ans;
    }
};
