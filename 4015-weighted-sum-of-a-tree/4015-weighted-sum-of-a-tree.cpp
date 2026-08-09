class Solution {
public:
    vector<vector<int>> adj;
    vector<int> depth;
    int h;
    
    void dfs(int node, int d){
        depth[node] = d;
        h = max(h, d);

        for(int child : adj[node]){
            dfs(child, d+1);
        }
    }
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        adj.assign(n, {});
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }

        depth.assign(n, 0);
        h = 0;
        
        dfs(0,1);

        long long ans = 0;

        for(int i=0;i<n;i++){
            ans += 1LL * nums[i] * (h - depth[i] + 1);
        }

        return ans;
    }
};