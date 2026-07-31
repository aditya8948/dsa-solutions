class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for(char ch : word){
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());
        int pushes = 0;

        for(int i = 0; i < 26; i++){
            int press = (i/8)+1;
            pushes += press*freq[i];
        }
        return pushes;
    }
};