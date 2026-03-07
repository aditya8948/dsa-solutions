class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freqS(265 , 0) ;
        vector<int> freqT(265 , 0);
        // storing freq of each character of t string
        int distinctElement = 0;
        for(int i = 0 ; i < t.size() ; i++){
            if(freqT[t[i]] == 0) distinctElement++;
            freqT[t[i]]++;
        }

        //searching for smallest string start  from 0 index and contain all element of t
        int count = 0;
        int start = 0;
        int end ;
        for(int  i = start ; i < s.size() ; i++){
            freqS[s[i]]++;
            if(freqS[s[i]] == freqT[s[i]]) count++;
            if(count == distinctElement) {
                end = i;
                break;
            }
        }

        if(count < distinctElement) return "";
        int ansStart = 0 ;
        int ansEnd = end;
        int length = ansEnd - ansStart + 1;
        while(end < s.size() ){

            while(freqS[s[start]] > freqT[s[start]]){
                freqS[s[start]]--;
                start++;
            }
            if(length > end-start+1){
                length = end-start+1;
                ansStart = start;
                ansEnd = end;
            }
            // cout<< length ;

            end++;
            if(end < s.size())
                freqS[s[end]]++;

        }
    return s.substr(ansStart , length );
    }
};