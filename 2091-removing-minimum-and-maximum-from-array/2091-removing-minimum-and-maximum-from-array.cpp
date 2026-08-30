class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN, mini = INT_MAX, maxInd = 0, minInd = 0;
        for(int i=0;i<n;i++){
            if(maxi < nums[i]) {
                maxi = nums[i];
                maxInd = i;
            } 
            if(mini > nums[i]){
                mini = nums[i];
                minInd = i;
            }
        }

        int left = max(maxInd, minInd) + 1;
        int right = n - min(maxInd, minInd);
        int mixed = min(maxInd + 1 + (n - minInd), minInd + 1 + (n - maxInd));

        return min({left, right, mixed});
    }
};