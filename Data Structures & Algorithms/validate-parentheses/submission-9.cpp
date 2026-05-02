#include <stack>

class Solution {
   public:
    bool isValid(string s) {
        std::stack<char> op;  // 'op' is the opening bracket stack

        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '{':
                case '(':
                case '[':
                    op.push(s[i]);
                    break;
                case '}':
                    if (op.empty() || op.top() != '{') {
                        return false;
                    }
                    op.pop();
                    break;
                case ')':
                    if (op.empty() || op.top() != '(') {
                        return false;
                    }
                    op.pop();
                    break;
                case ']':
                    if (op.empty() || op.top() != '[') {
                        return false;
                    }
                    op.pop();
                    break;
                default:
                    break;
            }
        }
        return op.empty();
    }
};
