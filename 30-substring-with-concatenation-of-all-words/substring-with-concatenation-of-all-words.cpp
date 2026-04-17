class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int l = words.size();
        int m = words[0].size();
        vector<int> ans;

        if(n < l*m) return ans;
    
        unordered_map<string, int> freqMap;
        for(string &w : words){
            freqMap[w]++;
        }

        // trying all offset 
        for(int offset = 0 ; offset < m ; offset++){
            int left = offset;
            int count = 0;
            unordered_map<string,int> temp;

            for(int right = offset ; right+m <= n ;right+=m){
                string word = s.substr(right,m);

                // CASE 1: valid string
                if(freqMap.find(word) != freqMap.end()){
                    temp[word]++;
                    count++;

                    //CASE 2: frequency exceed => now shrink the window 
                    while(temp[word] > freqMap[word]){
                        string leftWord = s.substr(left,m);
                        temp[leftWord]--;
                        count--;
                        left+=m;
                    }

                    // CASE 3: find valid window
                    if(count == l){
                        ans.push_back(left);
                        // move window forward 
                        string leftWord = s.substr(left,m);
                        temp[leftWord]--;
                        count--;
                        left+=m;
                    }
                }

                else {
                    // CASE 4: invalid word=> reset window 
                    temp.clear();
                    count = 0 ;
                    left = right+m;
                }
            }
        }
        return ans;
    }
};