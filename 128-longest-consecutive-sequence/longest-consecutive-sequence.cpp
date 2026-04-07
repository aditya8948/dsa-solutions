class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m ;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){

            if(m.find(nums[i]) != m.end()) continue ; // element is already present 

            int leftStreak = 0 ;
            int rightStreak = 0;

            if(m.find(nums[i] - 1) != m.end()) leftStreak = m[nums[i] - 1];
            if(m.find(nums[i] + 1) != m.end()) rightStreak = m[nums[i] + 1];
            int val = 1 + leftStreak + rightStreak;
            m[nums[i]] = val;
            ans = max(ans , val);
            m[nums[i] - leftStreak] = val;
            m[nums[i] + rightStreak] = val;
            
        }
    return ans;
    }
};