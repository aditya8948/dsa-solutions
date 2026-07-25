class Solution {
public:
    int maxProduct(int n) {
        int number = n;
        int max = INT_MIN;
        int secondMax = INT_MIN;
        int position = -1;
        int i = 1;
        while(n > 0){
            int num = n%10;
            if(num > max) {
                max = num;
                position = i;
            }
            i++;
            n/=10;
        }
        int j =1;
        while(number > 0){
            int num = number%10;

            if(num >= secondMax && j != position){
                secondMax = num;
            }
            number/=10;
            j++;
        }
        return max*secondMax;
    }
};