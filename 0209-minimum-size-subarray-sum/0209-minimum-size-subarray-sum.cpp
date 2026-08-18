class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for(int x : nums){
            total += x;
        }
        if(total < target) return 0;

        int ans = n;
        int sum = 0;
        
        int l = 0, r = 0;
        while(r < n){
            sum += nums[r];
            while(sum >= target){
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            } 

            if(sum < target) r++;
            
        }

        return ans;

    }
};