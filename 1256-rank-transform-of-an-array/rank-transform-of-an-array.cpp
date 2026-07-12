class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        int rank = 1;
        unordered_map<int, int> m;
        vector<int> temp(arr.size());

        for(int i = 0; i < n; i++){
            temp[i] = arr[i];
        }

        sort(temp.begin() , temp.end());

        for(int i = 0; i < n; i++){
            if( m.count(temp[i]) ) continue;
            
            m[temp[i]] = rank;
            rank++;
        }

        for(int i = 0; i < n; i++){
            arr[i] = m[arr[i]];
        }

        return arr;
    }
};