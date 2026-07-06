class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string valid ="";
        int openB = 0;
        for(char c : s){
            if(c == ')' && openB == 0) continue;

            valid.push_back(c);
            if(c == '(') openB++;
            if(c == ')') openB--;
        }
        
        string ans = "";

        for(int i = valid.size()-1; i >= 0; i--){
            if(valid[i] == '(' && openB > 0) {
                openB--;
                continue;
            }
            ans.push_back(valid[i]);
        }
       
        reverse(ans.begin() , ans.end());

        return ans;
    }
};