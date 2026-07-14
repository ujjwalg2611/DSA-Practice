class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    
    ll helper(int i,int seq1,int seq2,vector<int>& nums){
        if(i == nums.size()) {
            if(seq1 != seq2 || (seq1 == 0 && seq2 == 0)) return 0;
            return 1;
        }

        if(dp[i][seq1][seq2] != -1) return dp[i][seq1][seq2];

        int gcd_1 = gcd(seq1, nums[i]);
        int gcd_2 = gcd(seq2, nums[i]);

        ll pick1 = helper(i+1,gcd_1,seq2,nums);
        ll pick2 = helper(i+1,seq1,gcd_2,nums);
        ll skip = helper(i+1,seq1,seq2,nums);

        return dp[i][seq1][seq2] = (pick1 + pick2 + skip) % MOD;
    }
    
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        dp.assign(n, vector<vector<int>>(mx+1, vector<int>(mx+1, -1)));
        return helper(0,0,0,nums);
    }
};