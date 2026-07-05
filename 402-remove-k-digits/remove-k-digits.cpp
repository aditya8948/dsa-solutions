class Solution {
public:
    string removeKdigits(string num, int k) {
        string s = "";
        int i = 0;
        int n = num.size();
        while(i < n && k > 0){
            while(!s.empty() && s.back() > num[i]){
                s.pop_back();
                k--;
                if(k == 0) break;
            }
            s.push_back(num[i]);
            i++;
        }
        while(i < n){
            s.push_back(num[i]);
            i++;
        }
        while (k > 0) {
            s.pop_back();
            k--;
        }
        int idx = 0;
            while (idx < s.size() && s[idx] == '0')
            idx++;

            s = s.substr(idx);      

        return s.empty() ? "0" : s;
    }
};