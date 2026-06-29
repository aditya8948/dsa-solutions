class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 1) return heights[0];
        vector<int> NSE(n);
        vector<int> PSE(n);
        int result = INT_MIN;
        stack<int> st;

        // precompution Next shortest element 
        st.push(0);
        for(int i = 1; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()] ){
                NSE[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            NSE[st.top()] = n;
            st.pop();
        }
        // precomputing previous shortest element 

        st.push(n-1);
        for(int i = n-2; i >= 0; i--){
            while(!st.empty() && heights[i] < heights[st.top()] ){
                PSE[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            PSE[st.top()] = -1;
            st.pop();
        }
        

        // main logic

        for(int i = 0; i < n; i++){
            result = max(result , (NSE[i] - PSE[i] -1 ) * heights[i]);
        }
        return result;
    }
};