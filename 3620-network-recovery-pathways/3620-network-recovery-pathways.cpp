class Solution {
public:
    bool dijkstra(int maxEdge,long long k,int n,vector<vector<pair<int,int>>>& adj){
        vector<long long> dist(n,LLONG_MAX);
        dist[0] = 0;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto [costSoFar, node] = pq.top();
            pq.pop();

            if(costSoFar > dist[node]) continue;

            if(node == n-1) return costSoFar <= k;

            for(auto &it : adj[node]){
                int next = it.first;
                int cost = it.second;

                if(cost < maxEdge) continue;

                long long nextCost = costSoFar + cost;
                if(nextCost > k) continue;

                if(nextCost < dist[next]){
                    dist[next] = nextCost;
                    pq.push({nextCost,next});
                }
            }


        }

        return false;
        
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        if(!online[0] || !online[n-1]) return -1;

        int maxEdge = 0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if(online[u] && online[v]) {
                adj[u].push_back({v,wt});
                maxEdge = max(maxEdge,wt);
            }
        }

        int low = 0, high = maxEdge;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(dijkstra(mid,k,n,adj)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};