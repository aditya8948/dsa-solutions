class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num % 3 != 0) return {};

        long long val = num/3;
        return {val-1, val , val+1};
    }
};