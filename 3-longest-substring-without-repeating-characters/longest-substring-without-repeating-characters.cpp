class Solution {
public:
    
    // check substring
    bool isValid(string sub, char ch) {
        for(int i = 0; i < sub.size(); i++) {
            if(sub[i] == ch)
                return false;
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;

        for(int i = 0; i < s.size(); i++) {
            string subString = "";
            subString += s[i];     
            int len = 1;

            for(int j = i + 1; j < s.size(); j++) {
                if(isValid(subString, s[j])) {
                    subString += s[j];
                    len++;
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
