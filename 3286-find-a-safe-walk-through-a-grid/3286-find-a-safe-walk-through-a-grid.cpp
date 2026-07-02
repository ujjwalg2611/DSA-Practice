class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1 && grid[m-1][n-1] == 1 && health < 3) return false;

        int reqHealth = 0;

        vector<vector<int>> vis(m, vector<int>(n,0));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0],0,0});

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        while(!pq.empty()){
            auto [h, row, col] = pq.top();
            pq.pop();

            if(vis[row][col]) continue;
            vis[row][col] = 1;

            if(row == m-1 && col == n-1) {
                return h < health;
            }

            for(int i=0;i<4;i++){
                int nr = row + dx[i];
                int nc = col + dy[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]){
                    pq.push({h + grid[nr][nc],nr,nc});
                }
            }
        }

        return false;
        
    }
};