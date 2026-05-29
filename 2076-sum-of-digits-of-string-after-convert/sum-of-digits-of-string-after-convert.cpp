class Solution {
public:
    int getLucky(string s, int k) {
        string code ;
        for(char ch: s){
            code += to_string(ch - 'a' + 1);
        }

        int sum = 0;
         for (char ch : code) {
            sum += ch - '0';
        }
        k--;
         while(k > 0){
            int num = 0 ;
            while(sum > 0){
                num+= sum%10;
                sum = sum/10;
            }
            sum = num;
            k--;
         }
         return sum;
    }
};