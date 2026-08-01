class Solution {
public:
    int solve(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if(l == r) return nums[l];

        if(dp[l][r] != -1) return dp[l][r];

        int takeLeft = nums[l] - solve(nums,l+1,r,dp);
        int takeRight = nums[r] - solve(nums,l,r-1,dp);

        return dp[l][r] = max(takeLeft, takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(nums, 0, n-1, dp) >= 0;
    }
};