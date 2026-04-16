class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        vector<int> res;
        map<int , vector<int>> m;
        int n = nums.size();


        // inserting nums in map 
        for(int i = 0 ; i < n; i++){
            m[nums[i]].push_back(i);
        }


        for(int i = 0 ; i < queries.size() ; i++){
            int q = queries[i];
            int num = nums[q];

            vector<int>& v = m[num];
            int sz = v.size();
            // single occurance element 
            if(v.size() == 1){
                res.push_back(-1);
                continue;
            }

            // multiple occurance element 

            // binary search to find the ind 
            int left = 0;
            int right = v.size()-1;
            int index;
            while(left <= right){
                int mid = left+(right-left)/2;
                if(v[mid] == q) {
                    index = mid;
                    break;
                }
                else if(v[mid] < q) left=mid+1;
                else right=mid-1;
            }

            int dist = INT_MAX;
            // for right side 
            int rightDis = v[(index+1) % sz];
            int d= abs(q-rightDis);
            int circularDis = n-d;
            dist = min({dist,d,circularDis});

            // for left side 
            int leftDis = v[(index-1+sz)%sz];
            d = abs(q-leftDis);
            circularDis = n-d;
            dist = min({dist,d,circularDis});
            
            res.push_back(dist);

        }
        return res;
    }
};