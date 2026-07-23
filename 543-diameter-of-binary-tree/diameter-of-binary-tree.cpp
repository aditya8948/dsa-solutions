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
    pair<int, int> solve(TreeNode* root){
        if(!root) return {0,0};

        pair<int,int> lst = solve(root->left);
        pair<int,int> rst = solve(root->right);

        int d = max( {1+lst.first+rst.first, lst.second, rst.second});
        int h = 1 + max(lst.first, rst.first);

        return {h, d};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).second-1;

    }
};