class Solution {
public:
    bool isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    int dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int dx[], int dy[]) {
        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] = 1;
        int area = 1;

        for(int i=0;i<4;i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(isValid(nrow, ncol, m, n) && !vis[nrow][ncol] && grid[nrow][ncol]) {
                area += dfs(nrow, ncol, vis, grid, dx, dy);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!vis[i][j] && grid[i][j]){
                    ans = max(ans, dfs(i,j,vis,grid,dx,dy));
                }
            }
        }

        return ans;
    }
};