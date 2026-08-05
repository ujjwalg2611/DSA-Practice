class Solution {
public:
    void dfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
        vis[start] = 1;
        for(auto &nei : adj[start]){
            if(!vis[nei]){
                dfs(nei, adj, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans;
        vector<vector<int>> adj(n);
        
        for(auto &e : invocations){
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(n, 0);
        dfs(k, adj, vis);

        for(auto &e : invocations){
            if(!vis[e[0]] && vis[e[1]]){
                vector<int> ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }

                return ans;
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]) ans.push_back(i);
        }

        return ans;

    }
};