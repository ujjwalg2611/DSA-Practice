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
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->left == p && root->right == q) return root;
        if(root->left == q && root->right == p) return root;
        if(root == p || root == q) return root;

        TreeNode* left = dfs(root->left,p,q);
        TreeNode* right = dfs(root->right,p,q);

        if(left && right) return root;
        if(!left && right) return right;
        if(left && !right) return left;
    

        return NULL;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};