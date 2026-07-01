class Solution {
public:
    string countAndSay(int n) {
       string s = "1";

       for(int steps = 2; steps<= n; steps++){
        string ans = "";
        int count = 1;

        for(int i =1 ; i < s.size(); i++){
            if(s[i] == s[i-1]){
                count++;
            }
            else {
                ans += to_string(count);
                ans += s[i-1];
                count = 1;
            }
         }

         ans += to_string(count);
         ans += s.back();

         s = ans;
       }
        return s;
    }
};