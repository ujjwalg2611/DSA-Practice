class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfSets(int n, int k) {
        vector<int> dp(n), pref(n + 1);
        for (int j = 0; j < n; j++) {
            dp[j] = 1;
            pref[j + 1] = (pref[j] + dp[j]) % MOD;
        }
        for (int i = 1; i <= k; i++) {
            dp[0] = 0;
            for (int j = 1; j < n; j++) {
                dp[j] = (dp[j - 1] + pref[j]) % MOD;
            }
            for (int j = 0; j < n; j++) {
                pref[j + 1] = (pref[j] + dp[j]) % MOD;
            }
        }
        return dp[n - 1];
    }
};