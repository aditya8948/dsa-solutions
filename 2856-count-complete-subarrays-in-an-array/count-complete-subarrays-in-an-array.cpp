class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin() , nums.end());
        int distinctElement = st.size() ;
        int n = nums.size();
        unordered_map<int , int> freq;
        int ans = 0 , j = 0;

        for(int i = 0; i < n; i++){
            freq[nums[i]]++;

            while(freq.size() == distinctElement){

                ans += n - i;
                freq[nums[j]]--;
                if(freq[nums[j]] == 0) freq.erase(nums[j]);
                j++;
            }
        }
        return ans;

    }
};