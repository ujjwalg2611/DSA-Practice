class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    bool isValid(int r, int c, int m, int n){
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n,vector<int>(k+1,0)));

        queue<tuple<int,int,int,int>> q;
        q.push({0,0,0,0});
        vis[0][0][0] = 1;

        while(!q.empty()){
            auto [steps, row, col, obs] = q.front();
            q.pop();

            if(row == m-1 && col == n-1){
                return steps;
            }

            for(int i=0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(!isValid(nrow, ncol, m, n)) continue;

                int newObs = obs + grid[nrow][ncol];

                if(newObs > k) continue;

                if(!vis[nrow][ncol][newObs]){
                    vis[nrow][ncol][newObs] = 1;
                    q.push({steps+1, nrow, ncol, newObs});
                }
            }
        }
        return -1;
    }
};