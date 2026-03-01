class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> answer;
        vector<int> preXOR(n,0);
        preXOR[0] = arr[0];
        for(int i = 1 ; i < n ; i++){
            preXOR[i] = (preXOR[i-1] ^ arr[i]);
        }
        // cout<< queries.size();
        for(int i = 0 ; i < queries.size()  ; i++){
            int x = queries[i][0];
            int y = queries[i][1];
            int ans;
            if(x == 0) ans = preXOR[y];
            else 
            ans = (preXOR[y] ^ preXOR[x-1]);

            cout<< ans;

             
            answer.push_back(ans);

           
        }
        
        return answer ;
    }
};