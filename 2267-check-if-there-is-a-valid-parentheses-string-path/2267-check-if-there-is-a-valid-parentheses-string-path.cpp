class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {
        if (balance < 0) return false;

        if (i == n - 1 && j == m - 1) return balance == 0;

        if (dp[i][j][balance] != -1) return dp[i][j][balance];

        bool ans = false;

        if (i + 1 < n) {
            int nextBalance = balance + (grid[i + 1][j] == '(' ? 1 : -1);
            ans |= solve(grid, i + 1, j, nextBalance);
        }

        if (j + 1 < m) {
            int nextBalance = balance + (grid[i][j + 1] == '(' ? 1 : -1);
            ans |= solve(grid, i, j + 1, nextBalance);
        }

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if ((n + m - 1) % 2 != 0) return false;

        if (grid[0][0] != '(' || grid[n - 1][m - 1] != ')') return false;

        int startBalance = 1;

        dp.assign(n, vector<vector<int>>(m,vector<int>(n + m + 1, -1)));

        return solve(grid, 0, 0, startBalance);
    }
};