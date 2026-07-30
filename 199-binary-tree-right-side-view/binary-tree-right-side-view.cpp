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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;


        queue<pair<TreeNode*,int>> q;
        int  level = -1;
        q.push({root, 0});
        

        while(!q.empty()){
            pair<TreeNode*,int> n = q.front();
            q.pop();

            if(n.second > level){
                res.push_back(n.first->val);
                level = n.second;
            }

            if(n.first->right) q.push({n.first->right, n.second+1});
            if(n.first->left) q.push({n.first->left, n.second+1});
           
            
        }
        return res;
    }
};