https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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

    TreeNode* func(vector<int>& preorder, vector<int>& inorder, int pre_i, int pre_j, int in_i, int in_j){
        if(pre_i > pre_j || in_i > in_j) return NULL;
        if(pre_i == pre_j) return new TreeNode(preorder[pre_i]);

        int idx = find(inorder.begin(), inorder.end(), preorder[pre_i]) - inorder.begin();

        TreeNode* node = new TreeNode(preorder[pre_i]);
        node->left = func(preorder, inorder, pre_i+1, idx-in_i+pre_i, in_i, idx-1);
        node->right = func(preorder, inorder, idx-in_i+pre_i+1, pre_j, idx+1, in_j);
        
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return func(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};