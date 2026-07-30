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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        int ans = 0;


        while(!q.empty()){
            int size = q.size();
            unsigned long long minIndex = q.front().second;
            unsigned long long first = 0, last = 0;

            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                
                unsigned long long idx = node.second - minIndex;
                if(i == 0) first = idx;
                if(i == size-1) last = idx;

                if(node.first->left) q.push({node.first->left, 2*idx+ 1});
                if(node.first->right) q.push({node.first->right, 2*idx+ 2});
            }
            ans = max(ans, int(last-first+1));
        }
        return ans;
    }
};