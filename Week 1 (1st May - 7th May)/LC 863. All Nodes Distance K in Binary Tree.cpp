https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> par;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto fr = q.front();
            q.pop();

            if(fr->left){
                par[fr->left] = fr;
                q.push(fr->left);
            }

            if(fr->right){
                par[fr->right] = fr;
                q.push(fr->right);
            }
        }

        
        queue<pair<TreeNode*, int>> q1;
        q1.push({target, 0});

        // for(auto &x : par){
        //     cout << (x.first)->val << " " << (x.second)->val << endl;
        // }
        vector<int> ans;
        map<TreeNode*, bool> vis;
        vis[target] = true;
        while(!q1.empty()){
            auto [node, lev] = q1.front();
            q1.pop();

            if(lev == k){
                ans.push_back(node->val);
            }

            if(node->left and !vis.count(node->left)){
                q1.push({node->left, lev+1});
                vis[node->left] = true;
            }

            if(node->right and !vis.count(node->right)){
                q1.push({node->right, lev+1});
                vis[node->right] = true;
            }
            if(par.count(node) and !vis.count(par[node])){
                q1.push({par[node], lev+1});
                vis[par[node]] = true;
            }
        }
        
        return ans;
    }
};