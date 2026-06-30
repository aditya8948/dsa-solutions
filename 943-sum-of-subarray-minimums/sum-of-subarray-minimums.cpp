class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int m = 1e9 + 7;
        stack<int> stk;
        long long ans = 0;
        for(int i = 0; i < arr.size(); i++){
            while(!stk.empty() && arr[i] <= arr[stk.top()]){
                int mid = stk.top();
                int right = i;
                stk.pop();
                int left = stk.empty() ? -1: stk.top();

                int leftCount = mid - left;
                int rightCount = right - mid;

                long long sum = (1ll * leftCount * rightCount) % m;
                sum = (sum * arr[mid]) % m;
                ans = (ans+sum)%m;

            }
            stk.push(i);
        }
        // remaining elements
        while(!stk.empty()){
            int mid = stk.top();
            stk.pop();
            int left = stk.empty()?-1:stk.top();

            long long sum = (1ll*(n-mid) * (mid-left))%m;
            sum = (sum * arr[mid])%m;
            ans = (ans+sum)%m;
        }
        return ans;
    }
};