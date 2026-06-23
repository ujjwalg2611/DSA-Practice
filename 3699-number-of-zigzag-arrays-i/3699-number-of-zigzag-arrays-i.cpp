class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> up(m, 1);
        vector<long long> down(m, 1);

        vector<long long> pref(m);
        vector<long long> suff(m);
        vector<long long> nextUp(m);
        vector<long long> nextDown(m);

        for (int len = 2; len <= n; len++) {
            pref[0] = down[0];
            for (int i = 1; i < m; i++) {
                pref[i] = (pref[i - 1] + down[i]) % MOD;
            }

            suff[m - 1] = up[m - 1];
            for (int i = m - 2; i >= 0; i--) {
                suff[i] = (suff[i + 1] + up[i]) % MOD;
            }

            for (int i = 0; i < m; i++) {
                nextUp[i] = (i == 0 ? 0 : pref[i - 1]);
                nextDown[i] = (i == m - 1 ? 0 : suff[i + 1]);
            }

            up.swap(nextUp);
            down.swap(nextDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};