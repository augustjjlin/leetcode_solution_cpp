#include <string>
#include <deque>

using std::string;

class Solution {
 public:
    string simplifyPath(string path) {
        std::deque<string> files;
        int i = 0;

        while (i < path.size()) {
            while (i < path.size() && path[i] == '/') ++i;

            if (i == path.size()) break;

            string file_name("");
            while (i < path.size() && path[i] != '/') {
                file_name += path[i];
                ++i;
            }

            if (file_name == "..") {
                if (!files.empty()) files.pop_back();
            } else if (file_name == ".") {
                continue;
            } else {
                files.push_back(file_name);
            }
        }

        string result("");
        if (files.empty()) {
            result += "/";
        } else {
            while (!files.empty()) {
                string current_file = files.front();
                files.pop_front();
                result += ("/" + current_file);
            }
        }

        return result;
    }
};
