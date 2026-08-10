class Solution {
public:
    bool solve(int n, vector<bool>& dp){
        if(n == 0) return false;

        if(dp[n] != false) return dp[n];

        for(int i=1;i*i<=n;i++){
            int opp = n - i*i;
            if(!solve(opp, dp)) return dp[n] = true;
        }

        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        return solve(n, dp);
    }
};