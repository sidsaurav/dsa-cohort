https://leetcode.com/problems/path-sum-ii/

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
private:
    vector<vector<int>> ans;
public:

    void func(TreeNode* root, vector<int>& ele, int sum, int tar){
        ele.push_back(root->val);
        sum += root->val;
        if(root->left){
            func(root->left, ele, sum, tar);
        }

        if(root->right){
            func(root->right, ele, sum, tar);
        }

        if(root->left == NULL and root->right == NULL and sum == tar){
            ans.push_back(ele);
        }

        ele.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        vector<int> ele;
        func(root, ele, 0, targetSum);

        return ans;
    }
};