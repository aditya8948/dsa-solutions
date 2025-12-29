class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Time comlexity O(n) , space complexity => 0(n) extra  array 

        int n = nums.size();;
        // vector<int> leftProduct(n);
        // vector<int> rightProduct(n);
        // // prefix product
        // leftProduct[0] = 1;  // there  is no left product
        // for(int i = 1 ; i < n ; i++){
        //     leftProduct[i] = leftProduct[i-1] * nums[i-1];
        // }
        // // suffix product
        // rightProduct[n-1] = 1; //there  is  no right product
        // for(int i = n-2 ; i >= 0 ; i--){
        //     rightProduct[i] = rightProduct[i+1] * nums[i+1];
        // }
        // // final product = leftproduct*rightproduct
        // for(int i =0 ; i < n ;i++){
        //     nums[i] = leftProduct[i]*rightProduct[i];
        // }
        // return nums;

        // time complexity => O(n) , space complexity = O(1)
        // using without extra array 

        vector<int> result(n,1);
        // prefix product
        int prefix = 1;
        for(int i = 0 ; i < n ; i++){
            result[i] = prefix;
            prefix*= nums[i];
        }
        int suffix = 1 ;
        // suffix product
        for(int i = n-1 ; i >=0 ; i--){
            result[i] *= suffix;
            suffix*= nums[i];
        }
        return result;
    }
};