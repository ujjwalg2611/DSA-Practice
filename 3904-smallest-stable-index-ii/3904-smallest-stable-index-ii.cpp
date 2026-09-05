class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixSum[n], suffixSum[n];
        prefixSum[0] = nums[0];
        suffixSum[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            prefixSum[i] = max(prefixSum[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffixSum[i] = min(suffixSum[i+1],nums[i]);
        }
        int idx = -1;
        int score;
        for(int i=0;i<n;i++){
            score = prefixSum[i] - suffixSum[i];
            if(score <= k) {
                idx = i;
                break;
            }
        }
        return idx;
    }
};