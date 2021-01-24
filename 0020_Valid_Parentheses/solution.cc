#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
 public:
    bool isValid(string s) {
        stack<char> parentheses_stack;

        for (auto ch : s) {
            if (ch == '(' ||
                ch == '[' ||
                ch == '{') {
                parentheses_stack.push(ch);
                continue;
            }

            if (parentheses_stack.empty()) return false;

            char left = parentheses_stack.top();
            parentheses_stack.pop();

            if (ch == ')' && left != '(') return false;
            if (ch == ']' && left != '[') return false;
            if (ch == '}' && left != '{') return false;
        }

        return parentheses_stack.empty();
    }
};
