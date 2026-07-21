class Solution {
public:
    string decodeString(string s) {
        stack<string> stringStack;
        stack<int> numStack;

        for(int i = 0; i < s.size(); i++){

            // number incounterted
            if(isdigit(s[i])){
                int num = 0;

                while(i < s.size() && isdigit(s[i])){
                    num = num*10 + s[i]-'0';
                    i++;
                }
                numStack.push(num);
                i--;
            }
        

            // symbol other than ']'

            else if(s[i] != ']'){
                stringStack.push({s[i]});
            }

            // closing bracket is encountered

            else {

                string curr;
                while(stringStack.top() != "["){
                    curr= stringStack.top() + curr;
                    stringStack.pop();
                }

                // pop corresponding opening bracket
                stringStack.pop();

                int repeat = numStack.top();
                numStack.pop();

                string result;

                while(repeat--){
                    result+=curr;
                }
                
                stringStack.push(result);
            } 
        }
        string ans;

        while(!stringStack.empty()){
            ans = stringStack.top() + ans;
            stringStack.pop();
        }
        return ans;
    }
};