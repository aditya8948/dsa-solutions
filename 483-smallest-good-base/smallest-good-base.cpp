class Solution {
public:
    string smallestGoodBase(string n) {
        long num = stoll(n);
    
        for(int i = 63 ; i >= 1; i--){
            long left = 2 , right = num-1;
            
            while(left <=  right){
                long mid = left + (right - left) / 2;
                long val = 1 , x = 1;
                bool flag = false;
                for(int j = 1; j <= i; j++){
                    
                    if(val >  num) {
                        flag = true ; 
                        break;
                    }
                    if((num-val)/mid < x){
                        flag = true ;
                        break;
                    }
                    else {
                        x = x*mid;
                    }
                    val += x;
                }
                if(val == num && !flag ) return to_string(mid);
                else if( val > num || flag) right = mid-1;
                else left = mid+1;
            }
            
        
        }
        return to_string(num-1);
    }
};