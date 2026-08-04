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
    void inorderTraversal(TreeNode* root, vector<int>& inorder){
        if(root == NULL) return;

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int n = inorder.size();
        int l = 0, r = n-1;
        while(l < r){
            int sum = inorder[l] + inorder[r];
            if(sum == k) return true;
            else if(sum > k) r--;
            else l++;
        }
        return false;
    }
};