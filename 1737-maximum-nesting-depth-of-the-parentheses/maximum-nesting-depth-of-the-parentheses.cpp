class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        stack<int> st;
        for(char ch : s){
            if(ch == '('){
                count++;
                st.push(count);
            }
            else if(ch == ')'){
                ans = max(ans , st.top());
                st.pop();
                count--;
            }
        }
        return ans;
    }
};