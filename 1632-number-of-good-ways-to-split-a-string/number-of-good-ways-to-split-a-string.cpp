class Solution {
public:
    int numSplits(string s) {
        vector<int> right(26, 0);
        vector<int> left(26, 0);
        int leftDistinct = 0;
        int rightDistinct = 0;

        for(char c : s){
            if(right[c - 'a'] == 0) rightDistinct++;
            right[c - 'a']++;
        }

        int ans = 0;

        for(char c : s){
            if(left[c - 'a'] == 0) leftDistinct++;
            left[c - 'a']++;

            right[c - 'a']--;
            if(right[c - 'a'] == 0) rightDistinct--;

            if(leftDistinct == rightDistinct) ans++;
        }
        return ans;
    }
};