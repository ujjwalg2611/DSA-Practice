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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left){
                q.push(curr->left);
                parent[curr->left] = curr;
            }

            if(curr->right){
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        unordered_map<TreeNode*, bool> vis;

        queue<TreeNode* > q;
        q.push(target);
        vis[target] = true;

        int dist = 0;
        while(!q.empty()){
            int size = q.size();

            if(dist++ == k) break;

            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
            }

        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};