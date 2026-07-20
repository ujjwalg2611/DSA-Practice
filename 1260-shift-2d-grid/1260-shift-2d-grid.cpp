class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k = k % (m * n);

        vector<vector<int>> ans = grid;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int newIdx = (i * n + j + k) % (m * n);
                ans[newIdx / n][newIdx % n] = grid[i][j];
            }
        }

        return ans;
    }
};