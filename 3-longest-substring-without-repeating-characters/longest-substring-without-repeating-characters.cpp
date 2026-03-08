class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(s == "") return 0;
        if(size == 1 ) return 1;
    vector<int> freq(265,0);
    int length = 0;
    int ans = INT_MIN;
    int i = 0 , j= 0;

    while(j < s.size()){
        if(freq[s[j]] == 0){
            freq[s[j]]++;
            length++;
            j++;
        }
        else {
            freq[s[i]]--;
            i++;
            length--;
        }
          ans = max(ans , length );
    }
    return ans;
    }
};