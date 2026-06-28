class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> res(n, -1);
        stk.push((2*n-1) % n); 
        for(int i = 2*n-2; i >= 0; i--){
                while(!stk.empty() && nums[i%n] >= nums[stk.top()] ){
                    stk.pop();
                }
                if(i < n){
                    if(!stk.empty()) res[i] = nums[stk.top()];
                }
                stk.push(i%n);
           }
        return res;
    }
};