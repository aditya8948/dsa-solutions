class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> freq(26, 0);
        vector<int> present(26,0);
        
        for(char ch : s){
            freq[ch - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']--;
            if(present[s[i] - 'a'] == 1) continue; // element already present in the stack

            while(!st.empty()  &&  s[i] < st.top()  &&  freq[st.top() - 'a'] > 0){
                present[st.top() - 'a'] = 0;
               
                st.pop();
            }
            st.push(s[i]);
            present[s[i] - 'a'] = 1;
        }
        stack<char> reverse;
        while(!st.empty()){
            reverse.push(st.top());
            st.pop();
        }
       
        string res = "";
        while(!reverse.empty()){
            res.push_back(reverse.top());
            reverse.pop();
        }
        return res;
    }
};