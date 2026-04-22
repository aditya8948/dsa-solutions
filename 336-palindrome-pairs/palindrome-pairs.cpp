class Solution {
public:

    bool ispal(string& s , int i , int j){
        while(i <= j){
            if(s[i] != s[j]) return false ;
            i++,j--;
        }
        return true ;
    }


    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> mp;
        vector<vector<int>> ans;
        for(int i = 0 ; i < words.size() ; i++){
            string s  = words[i];
            reverse(s.begin() , s.end());
            mp[s] = i;
        }
        if(mp.count("")){
            for(int i = 0 ; i < words.size() ; i++){
                if(mp[""] != i && ispal(words[i] ,0 , words[i].size()-1))
                    ans.push_back({i,mp[""]});
            }
            
        }
        for(int i = 0;  i< words.size() ; i++){
            string left , right;
            for(int j = 0 ; j < words[i].size() ; j++){
                left.push_back(words[i][j]);
                right = words[i].substr(j+1);
                if(mp.count(left) && mp[left] != i && ispal(words[i] , j+1 , words[i].size()-1))
                    ans.push_back({i , mp[left]});
                    
                if(mp.count(right) && mp[right] != i && ispal(words[i] , 0, j))
                    ans.push_back({mp[right] , i});
            }
        }

    return ans;
       
    }
};

//  unordered_map<string,int> umap;
//         map<pair<int,int> ,bool> m;
//         vector<vector<int>> res;
        
//         // inserting the words in map in reverse order 
//         for(int i = 0 ; i < words.size() ; i++){
//             umap[string(words[i].rbegin() , words[i].rend())] = i;
//         }

//         for(int i = 0 ; i < words.size() ; i++){
//             int n = words[i].size();
//             // for empty string 
//             if(umap.find("") != umap.end() 
//                && umap[""] != i
//                && ispal(words[i], 0, n-1)
//                && m.find({i , umap[""]}) == m.end()
//                && m.find({umap[""], i}) == m.end()
//                ){
//                   m[{i, umap[""]}] = true;
//                   m[{umap[""], i}] = true;
//                   res.push_back({i , umap[""]});
//                   res.push_back({umap[""] , i});
//                }

//                // prefix substring 

//                for(int j = 0 ; j < n; j++){
//                  string prefix = words[i].substr(0 , j+1);
//                  if(umap.find(prefix) != umap.end()
//                     && umap[prefix] != i
//                     && ispal(words[i] , j+1 , words[i].size()-1)
//                     && m.find({i , umap[prefix]}) == m.end()
//                     ){
//                         m[{i , umap[prefix]}] = true ;
//                         res.push_back({i , umap[prefix]});
//                     }
//                }

//                // suffix substrings 

//                for(int j = n-1 ; j >= 0 ; j--){
//                 string suffix = words[i].substr(j, n-j);
//                  if(umap.find(suffix) != umap.end()
//                     && umap[suffix] != i
//                     && ispal(words[i] , 0 , j-1)
//                     && m.find({umap[suffix] , i}) == m.end()
//                     ){
//                         m[{umap[suffix] , i}] = true ;
//                         res.push_back({umap[suffix] , i});
//                     }

//                }
//          }
//         return res;