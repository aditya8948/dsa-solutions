class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n);
        stack<int> s;
        for(int i = n-1; i >= 0; i--){
           int count = 0;
           while(!s.empty() && s.top() < heights[i]){
                count++;
                s.pop();
           }

           if(!s.empty()) count++;
           result[i] = count;
           s.push(heights[i]);
        }
        return result;
    }
};