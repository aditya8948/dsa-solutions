#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;   // stores the final unique permutations

  
    void backtrack(vector<int>& nums, int i) {
        
        if (i == nums.size()) {
            result.push_back(nums);        // store the permutation
            return;
        }

        unordered_set<int> freq;           // used to avoid duplicate values at same level

        // Try all positions from i to end
        for (int j = i; j < nums.size(); j++) {

            // If this value already used at current depth, skip it
            if (freq.count(nums[j]))
                continue;

            freq.insert(nums[j]);          // mark value as used at this level

            swap(nums[i], nums[j]);      
            backtrack(nums, i + 1);        // recurse for next index
            swap(nums[i], nums[j]);      
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 1, 2};

    // Call function to generate unique permutations
    vector<vector<int>> ans = sol.permuteUnique(nums);

    // Print output
    cout << "Unique Permutations:\n";
    for (auto &v : ans) {
        cout << "[ ";
        for (int x : v)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
