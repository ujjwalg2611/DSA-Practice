class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i=0;i<n;i++) dp[i][i] = piles[i];

        for(int l=n-1;l>=0;l--){
            for(int r=l+1;r<n;r++){
                int takeLeft = piles[l] - dp[l+1][r];
                int takeRight = piles[r] - dp[l][r-1];
                
                dp[l][r] = max(takeLeft, takeRight);
            }
        }

        return dp[0][n-1] >= 0;

    }
};