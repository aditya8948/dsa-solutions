class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;

        stringstream ss(path);
        string token;

        while(getline(ss, token, '/')){
            if(token.empty() || token == ".") continue;
            else if(token == "..") {
                if(!s.empty()) s.pop_back();
            }
            else s.push_back(token);
        }

        string ans ;

        for(string dir : s){

             ans += "/" + dir ;
        }
        return ans.empty() ? "/" : ans;
    }
};