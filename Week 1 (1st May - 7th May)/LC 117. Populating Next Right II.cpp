https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

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

    int func(TreeNode* root){
        if(!root) return 0;
        if(root->left == NULL and root->right == NULL) return 1;

        int h1 = 2e9, h2 = 2e9;
        if(root->left) h1 = func(root->left);
        if(root->right) h2 = func(root->right);

        return min(h1, h2) + 1;
    }

    int minDepth(TreeNode* root) {
        return func(root);
    }
};