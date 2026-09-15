class Solution {
public:
    int solve(int i, string& s, int k, vector<vector<int>>& pal, vector<int>& dp) {
        int n = s.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = solve(i + 1, s, k, pal, dp);

        for (int j = i + k - 1; j < n; j++) {
            if (pal[i][j]) {
                ans = max(ans, 1 + solve(j + 1, s, k, pal, dp));
            }
        }

        return dp[i] = ans;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<int>> pal(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = 1;
                }
            }
        }

        vector<int> dp(n, -1);
        return solve(0, s, k, pal, dp);
    }
};