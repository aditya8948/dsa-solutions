class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0); // maintain frequency of each character 
        int left = 0;             
        int maxFreq = 0;      // cur lenght tak maxfreq kitni hai 
        int maxWindow = 0;    // store  answer 

        for(int right = 0; right < s.length(); right++){ 
            freq[s[right] - 'A']++;                  // update freq of  character 
            maxFreq = max(maxFreq, freq[s[right] - 'A']);   // check the max freq
            int curLength = right - left+1 ;            // current window size 
            if(curLength - maxFreq > k){         // agar ye condition true hai mtlb ab isse jyada change nhi kr skate so shrink the window 
            // cout<< curLength ;
                freq[s[left] - 'A']--;  // remove contribution from freq array 
                left++; 
            }
            curLength = right - left + 1; // update curr length 
            maxWindow = max(maxWindow, curLength); // update  max
        }
        return maxWindow;
    }
};
