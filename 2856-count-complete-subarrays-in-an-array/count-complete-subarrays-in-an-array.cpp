class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int distinct = st.size();

        int ans = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            unordered_set<int> f;
            for(int j = i; j < nums.size(); j++){
                f.insert(nums[j]);

                if(f.size() == distinct) ans++;
            }
        }
        return ans;

    }
};