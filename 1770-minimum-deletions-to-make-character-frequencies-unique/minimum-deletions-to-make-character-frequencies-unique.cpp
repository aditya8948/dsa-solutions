class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(char ch : s){
            freq[ch - 'a']++;
        }

        int count = 0;
        unordered_set<int> used;

        for(int f : freq){
            while(f > 0 && used.count(f)){
                f--;
                count++;
            }
            if(f > 0) used.insert(f);
        }
        
        return count;
    }
};