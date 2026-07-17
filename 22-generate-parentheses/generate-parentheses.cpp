class Solution {
public:
    vector<string> res;
    int N;
    // recusrsion logic

    void solve(string& temp, int open, int close){

        //base case 
        if(temp.size() == 2*N){
            res.push_back(temp);
            return;
        }

        if(open < N){
            temp.push_back('(');

            solve(temp, open+1, close);

            temp.pop_back();
        }

        if(close < open && close < N){
            temp.push_back(')');

            solve(temp, open, close+1);

            temp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        N = n;
        string temp;
        solve(temp, 0, 0);

        return res;
    }
};