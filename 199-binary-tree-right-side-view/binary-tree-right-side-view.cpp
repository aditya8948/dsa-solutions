class Solution {
public:
    vector<int> res;

    void rightView(TreeNode* node, int level) {
        if (!node) return;

        if (level == res.size())
            res.push_back(node->val);

        rightView(node->right, level + 1);
        rightView(node->left, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        rightView(root, 0);
        return res;
    }
};