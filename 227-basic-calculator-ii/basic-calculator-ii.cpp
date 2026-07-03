class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        char sign = '+';

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            if ((!isdigit(ch) && ch != ' ') || i == s.size() - 1) {

                if (sign == '+') {
                    stk.push(num);
                }
                else if (sign == '-') {
                    stk.push(-num);
                }
                else if (sign == '*') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top * num);
                }
                else if (sign == '/') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top / num);
                }

                sign = ch;
                num = 0;
            }
        }

        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};