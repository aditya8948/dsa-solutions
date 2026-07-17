class Solution {
public:
    vector<vector<int>> res;
    int N;

    void solve(vector<int>& nums, vector<int>& temp , unordered_set<int>& usedDigit){

        if(temp.size() == N){
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < N; i++){

            if(usedDigit.count(nums[i])) continue;

            temp.push_back(nums[i]);
            usedDigit.insert(nums[i]);

            solve(nums, temp, usedDigit);

            temp.pop_back();
            usedDigit.erase(nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        N = nums.size();
        vector<int> temp;
        unordered_set<int> usedDigit;
        solve(nums,temp, usedDigit);

        return res;
    }
};