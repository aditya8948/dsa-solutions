class Solution {
public:
    bool rotateString(string s, string goal) {
        vector<int> sfreq(26,0);
         vector<int> goalfreq(26,0);
         for(char ch : s){
            sfreq[ch - 'a']++;
         }
         for(char ch : goal){
            goalfreq[ch - 'a']++;
         }

         for(int i = 0 ; i < 26; i++){
            if(sfreq[i] != goalfreq[i]) return false;
         }
         return true;
    }
};