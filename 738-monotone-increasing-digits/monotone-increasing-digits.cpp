class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        
        string s = to_string(n);
        int modified = s.size() ;
        for(int i = s.size()-1; i > 0; i--){
            if(s[i-1] > s[i]){
                s[i-1]--;
                modified = i;
            }
        }

        for(int i = s.size()-1; i >= modified ; i-- ){
            s[i] = '9';
        }

        

        return stoi(s);
    }
};