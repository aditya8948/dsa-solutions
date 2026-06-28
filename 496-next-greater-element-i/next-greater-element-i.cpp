class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        // precomputation of NGE for nums2
        stack<int> stk;
        unordered_map<int, int> mp;
        stk.push(nums2[0]);
        for(int i = 1; i < n2; i++){
            while( !stk.empty() && nums2[i] > stk.top()){
                mp[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        while(!stk.empty()){
            mp[stk.top()] = -1;
            stk.pop();
        }
       

       // result
        vector<int>res(n1);
       for(int i = 0; i < n1; i++){
            res[i] = mp[nums1[i]];
       }
       return res;
    }
};