class Solution {
public:
    void solve(int idx , string &digits , string &temp , map<char , string>& m , vector<string> &res ){
        if(idx == digits.size()){
            res.push_back(temp);
            return ;
        }

        char ch = digits[idx];
        string alphabet = m[ch];

        for(int i = 0 ;  i < alphabet.size() ; i++){
            temp.push_back(alphabet[i]);
            solve(idx+1 , digits , temp , m ,res);
            temp.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string temp = "";
        int idx = 0;
        map<char , string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        solve(idx , digits , temp , m , res);

        return res;
    }
};