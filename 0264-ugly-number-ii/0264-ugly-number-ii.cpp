class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int i2 = 1, i3 = 1, i5 = 1;
        for(int i=2;i<=n;i++){
            int next2 = dp[i2] * 2;
            int next3 = dp[i3] * 3;
            int next5 = dp[i5] * 5;

            dp[i] = min({next2, next3, next5});

            if(dp[i] == next2) i2++;
            if(dp[i] == next3) i3++;
            if(dp[i] == next5) i5++;
        }
        return dp[n];
    }
};