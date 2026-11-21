class Solution {
public:
    vector<int> answer;
    vector<vector<int>> adj;
    vector<int> newParent;

    void dfs(int node, vector<int>& parent, string& s,vector<int>& last) {
        int ch = s[node] - 'a';
        int original = last[ch];

        if (original != -1)
            newParent[node] = original;
        else
            newParent[node] = parent[node];

        last[ch] = node;

        for (int child : adj[node]) {
            dfs(child, parent, s, last);
        }

        last[ch] = original;
    }

    int dfsSize(int node, vector<vector<int>>& tree) {
        int sz = 1;

        for (int child : tree[node]) {
            sz += dfsSize(child, tree);
        }

        answer[node] = sz;
        return sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.resize(n);
        newParent.resize(n);
        answer.resize(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);

        dfs(0, parent, s, last);

        vector<vector<int>> newTree(n);

        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        dfsSize(0, newTree);

        return answer;
    }
};