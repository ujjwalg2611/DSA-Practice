class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        dp[0] = 1;
        for(int i=1;i<n;i++){
            if(nums[i-1] != nums[i]) dp[i] = dp[i-1] + 1;
        }
        long long ans = 0;
        for(int x : dp) ans += x;

        return ans;
    }
};