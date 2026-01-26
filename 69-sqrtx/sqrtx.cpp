class Solution {
public:
    int mySqrt(int x) {
        int left = 0; 
        int right = x;
        while(left <= right ){
            long long mid = (left+right)/2;
            if(mid*mid <= x && (mid+1)*(mid+1) > x)
                return mid;

            else if(mid*mid < x)
                left = mid+1;
            
            else 
                right = mid-1;
            
            }
            return 0;
    }
};