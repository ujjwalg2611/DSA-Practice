class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int x : nums){
            mx = max(mx, x);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans += mx - nums[i];
        }

        return ans;
    }
};