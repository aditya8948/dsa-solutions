class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x = INT_MAX;
        int y = INT_MAX;
        int z = INT_MAX;
        bool result = false;
        for(int i = 0 ; i < nums.size() ; i++){
           if(x >= nums[i]){
            x = nums[i];
           }
           else if(y >= nums[i] && nums[i] > x){
            y = nums[i];
           }
           else if(z >= nums[i] && nums[i] > y){
                z = nums[i];
                result = true  ;
           }
    }
    if(result == true ) return true;
    else 
    return false ;

    }
};