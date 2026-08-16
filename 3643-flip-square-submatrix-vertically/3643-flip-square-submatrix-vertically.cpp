class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        for(int j=0;j<k;j++){
            int l = x, r = x+k-1;
            while(l < r){
                swap(grid[l][j+y], grid[r][j+y]);
                l++;
                r--;
            }
        }

        return grid;
    }
};