class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0 ;
        int high = letters.size()-1;
        int ans = letters[0];    // default  answer 
        while (low <= high){
            int mid = low +(high -low)/2;
            if (letters[mid] <= target) low = mid+1;     // letter ya to chota hai ya equal (we are at  left  site)
            else {
                ans = letters[mid];    // right side of answer
                high = mid-1;       // 
            }
        }
        return ans;

    }
};