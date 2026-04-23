class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        typedef long long ll;
        int n = nums.size();
        vector<ll> res(n,0);
        unordered_map<int , ll> indexFreq; // store indexfreq of index
        unordered_map<int , ll> indexSum;   // store sum 0f indices appear till now 

        // left to right 
        for(int i = 0; i < n; i++){
            ll freq = indexFreq[nums[i]];
            ll sum  = indexSum[nums[i]];

            res[i]+= freq*i - sum;    // formula 
            indexFreq[nums[i]]++;
            indexSum[nums[i]]+= i;
        }

        indexFreq.clear();
        indexSum.clear();

        for(int i = n-1 ; i >= 0; i--){
            ll frq = indexFreq[nums[i]];
            ll sum = indexSum[nums[i]];

            res[i]+= sum - frq*i; // formula 

            indexFreq[nums[i]]++;
            indexSum[nums[i]]+=i;
        }
        return res;
    }
};