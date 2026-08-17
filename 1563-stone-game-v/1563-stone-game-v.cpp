class Solution {
public:
    int solve(int l,int h,vector<int>& stoneValue,vector<vector<int>>& dp){
        if(l == h) return 0;

        if(dp[l][h] != -1) return dp[l][h];

        int ans = 0;
        
        int leftSum = 0;
        int totalSum = 0;

        for(int i=l;i<=h;i++){
            totalSum += stoneValue[i];
        }


        for(int k=l;k<h;k++){

            leftSum += stoneValue[k];
            int rightSum = totalSum - leftSum;
            
            if(leftSum < rightSum){
                ans = max(ans, leftSum + solve(l, k, stoneValue,dp));
            } else if(leftSum > rightSum){
                ans = max(ans, rightSum + solve(k+1, h, stoneValue,dp));
            }else {
                ans = max(ans, leftSum + solve(l, k, stoneValue,dp));

                ans = max(ans, rightSum + solve(k+1, h, stoneValue,dp));
            }

        }

        return dp[l][h] = ans;

    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if(n == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, stoneValue, dp);
    }
};