class Solution {
public:
    bool isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& heights, int dx[], int dy[]) {
        int m = heights.size();
        int n = heights[0].size();

        vis[r][c] = 1;

        for(int i=0;i<4;i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(isValid(nr, nc, m, n) && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, vis, heights, dx, dy);
            } 
        }
    
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        for(int i=0;i<m;i++) dfs(i,0,pacific,heights,dx,dy);
        for(int j=0;j<n;j++) dfs(0,j,pacific,heights,dx,dy);

        for(int i=0;i<m;i++) dfs(i,n-1,atlantic,heights,dx,dy);
        for(int j=0;j<n;j++) dfs(m-1,j,atlantic,heights,dx,dy);


        vector<vector<int>> ans;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};