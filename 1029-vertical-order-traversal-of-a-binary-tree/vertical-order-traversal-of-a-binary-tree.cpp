/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        unordered_map<int, vector<pair<int, int>>> map;

        int minn = INT_MAX,  maxx = INT_MIN;
        
        while(!q.empty()){
            auto v = q.front();
            q.pop();

            TreeNode* node = v.first;
            int col = v.second.second;
            int row = v.second.first;

            map[col].push_back({row, node->val});
            minn = min(minn, col);
            maxx = max(maxx, col);

            if(node->left) q.push({node->left, {row+1, col-1}});
            if(node->right) q.push({node->right, {row+1, col+1}});
        }
          vector<vector<int>> ans;

        for (int col = minn; col <= maxx; col++) {

            auto &v = map[col];

            sort(v.begin(), v.end(), [](auto &a, auto &b) {
                if (a.first == b.first)
                    return a.second < b.second;   // same row -> smaller value
                return a.first < b.first;         // smaller row first
            });

            vector<int> temp;
            for (auto &p : v)
                temp.push_back(p.second);

            ans.push_back(temp);
        }

        return ans;
    }
};