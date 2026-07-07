class Solution {
public:
    bool checkValidString(string s) {
        stack<int> paranthesis;
        stack<int> asterisk;

        for(int i =0 ; i < s.size(); i++){
            if(s[i] == '('){
                paranthesis.push(i);
            }
            else if(s[i] == '*'){
                asterisk.push(i);
            }
            // c = ')'
            else if(!paranthesis.empty()) paranthesis.pop();
            else if(!asterisk.empty()) asterisk.pop();
            else return false;
        }

        while(!paranthesis.empty() && !asterisk.empty()){
            if(asterisk.top() < paranthesis.top()) return false;

            paranthesis.pop();
            asterisk.pop();
        }
        return paranthesis.empty();
    }
};