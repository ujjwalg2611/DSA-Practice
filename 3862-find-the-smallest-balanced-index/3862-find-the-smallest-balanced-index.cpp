class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return -1;

        vector<long long> prefSum(n+1,0), suffProd(n+1,1);

        for(int i=1;i<=n;i++) prefSum[i] = prefSum[i-1] + nums[i-1];

        for(int i=n-1;i>=0;i--) {
            if (suffProd[i + 1] > prefSum[n] / nums[i]) {
                suffProd[i] = prefSum[n] + 1;
            } else {
                suffProd[i] = suffProd[i + 1] * nums[i];
            }
        }

        for(int i=0;i<n;i++){
            if(prefSum[i] == suffProd[i+1]) return i;
        }

        return -1;
    }
};