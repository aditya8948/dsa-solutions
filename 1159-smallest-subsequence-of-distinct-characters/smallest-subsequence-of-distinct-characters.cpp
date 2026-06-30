class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> present(26, false);
        string res = "";
        for(char ch : s) freq[ch - 'a']++;

        for(char ch : s){
            freq[ch - 'a']--;

            if(present[ch - 'a']) continue;

            while(!res.empty() && ch < res.back() && freq[res.back() - 'a'] > 0) {
                present[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(ch);
            present[ch - 'a'] = 1;
        }
        return res;
    }
};