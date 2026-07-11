class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& comp) {
        vis[node] = 1;
        comp.push_back(node);
        for(auto &nei : adj[node]){
            if(!vis[nei]) {
                dfs(nei,adj,vis,comp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                vector<int> comp;
                dfs(i,adj,vis,comp);

                int nodes = comp.size();
                int degreeSum = 0;

                for(int u : comp){
                    degreeSum += adj[u].size();
                }

                int edgesInComp = degreeSum / 2;

                if(edgesInComp == nodes * (nodes - 1) / 2) cnt++;
            }
        }

        return cnt;
    }
};