class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> s;
        for(int i = 0; i < height.size(); i++){
            while(!s.empty() && height[i] > height[s.top()]){
                int mid = s.top();
                s.pop();
                
                if(s.empty()) break;

                int width = i - s.top() - 1;
                int boundedHeight = min(height[i],height[s.top()]) - height[mid];
                ans += width * boundedHeight;
            }
            s.push(i);
        }
        return ans;
    }
};