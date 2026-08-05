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
    void correctBST(TreeNode* root, vector<int>& inorder, int &i){
        if(root == NULL) return;

        correctBST(root->left, inorder, i);
        root->val = inorder[i++];
        correctBST(root->right, inorder, i);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        sort(inorder.begin(), inorder.end());
        int ptr = 0;
        correctBST(root, inorder, ptr);
    }
};