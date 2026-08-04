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
class BSTIterator {
public:
    vector<int> inorder;
    int n;
    int ptr;
    void inorderTraversal(TreeNode* root, vector<int>& inorder){
        if(root == NULL) return;

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
    BSTIterator(TreeNode* root) {
        inorderTraversal(root, inorder);
        n = inorder.size();
        ptr = -1;
    }
    
    int next() {
        return inorder[++ptr];
    }
    
    bool hasNext() {
        return (ptr < n-1 ? true : false);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */