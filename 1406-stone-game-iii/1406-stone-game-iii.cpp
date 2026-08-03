class Solution {
public:
    int solve(vector<int>& nums,int l,int n,vector<int>& dp){
        if(l >= n) return 0;

        if(dp[l] != -1) return dp[l];

        int ans = INT_MIN;
        int sum = 0;
        for(int i=l;i<min(n,l+3);i++){
            sum += nums[i];
            ans = max(ans, sum - solve(nums,i+1,n,dp));
        }

        return dp[l] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1);

        int ans = solve(stoneValue,0,n,dp);

        if(ans > 0) {
            return "Alice";
        } else if(ans < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};