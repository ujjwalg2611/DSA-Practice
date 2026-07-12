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
    void bfs(TreeNode* root,int &sum){
        queue<pair<TreeNode*, bool>> q;
        q.push({root, 0});

        while(!q.empty()) {
            auto [node, flag] = q.front();
            q.pop();

            if(node->left == NULL && node->right == NULL && flag == 1) {
                sum += node->val;
            }

            if(node->left) q.push({node->left,1});
            if(node->right) q.push({node->right,0});

        } 
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        bfs(root,sum);

        return sum;
    }
};