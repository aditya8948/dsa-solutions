class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        while(n >= i){
            n = n-i;
            i++;
        }
        return i-1; // total valid row = i-1 because i started  from 1;
      
    }
};