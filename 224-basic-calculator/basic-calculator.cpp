class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        long long num = 0;
        int result = 0;
        int sign = 1;  // -1 => subtarction , 1 => addition

        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                num = (num*10) + s[i]-'0';
            }

            else if(s[i] == '+'){
                result += (num*sign);
                num = 0;
                sign = 1;
            }

            else if(s[i] == '-'){
                result+= (num*sign);
                num = 0;
                sign = -1;
            }

            else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                num = 0;
                sign = 1;
            }

            else if(s[i] == ')'){
                result+= (num*sign);
                num = 0;

                int stack_sign = st.top(); st.pop();
                int stack_result = st.top(); st.pop();

                result*= stack_sign ;
                result+= stack_result;

            }
        }
        result+= (num*sign);
        return result;
    }
};