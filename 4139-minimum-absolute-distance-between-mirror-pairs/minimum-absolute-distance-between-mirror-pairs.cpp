class Solution {
public:
    int reverseNumber(int number){
        int rev = 0 ;
        while(number > 0){
            rev = rev*10 + (number%10);
            number/=10;
        }
        return rev ;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++){

            if(m.find(nums[i]) != m.end()){
                ans = min(ans, i - m[nums[i]]);
            }
            int num = reverseNumber(nums[i]);
            m[num] = i;
        }
        return ans == INT_MAX? -1 : ans;
    }
};