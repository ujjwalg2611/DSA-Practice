class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<long long> dp;
    vector<int> prev;

    long long solve(int i, string &s) {
        if (i == 0) return 1; 

        if (dp[i] != -1) return dp[i];

        long long ans = (2 * solve(i - 1, s)) % MOD;

        if (prev[i - 1] != -1) {
            ans = (ans - solve(prev[i - 1], s) + MOD) % MOD;
        }

        return dp[i] = ans;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        dp.assign(n + 1, -1);
        prev.assign(n, -1);

        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            prev[i] = last[c];
            last[c] = i;
        }

        return (solve(n, s) - 1 + MOD) % MOD;
    }
};