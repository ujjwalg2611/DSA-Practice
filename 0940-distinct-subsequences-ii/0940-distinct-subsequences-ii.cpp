class Solution { 
public: 
    int mod = 1e9 + 7; 
 
    int distinctSubseqII(string s) { 
        int n = s.size(); 
        vector<long long> dp(n + 1, 0); 
        dp[0] = 1; 
 
        vector<long long> last(26, 0); 
 
        for (int i = 1; i <= n; i++) { 
            int c = s[i - 1] - 'a'; 
 
            dp[i] = (2 * dp[i - 1]) % mod; 
            dp[i] = (dp[i] - last[c] + mod) % mod; 
            last[c] = dp[i - 1]; 
        } 
 
        return (dp[n] - 1 + mod) % mod; 
    } 
};