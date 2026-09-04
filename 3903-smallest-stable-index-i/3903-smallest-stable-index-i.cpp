class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int idx = -1;
        for(int i=0;i<n;i++){
            int maxi = INT_MIN, mini = INT_MAX;
            for(int j=0;j<=i;j++){
                maxi = max(maxi,nums[j]);
            }
            for(int j=i;j<n;j++){
                mini = min(mini,nums[j]);
            }
            int score = maxi - mini;
            if(score <= k){
                idx = i;
                break;
            }
        }
        return idx;
    }
};