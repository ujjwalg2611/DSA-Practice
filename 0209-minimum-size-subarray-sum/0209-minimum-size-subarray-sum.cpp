class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;

        int low = 1, high = n;
        while(low <= high){
            int mid = low + (high - low) / 2;

            int sum = 0;
            for(int i=0;i<mid;i++) sum += nums[i];

            bool possible = sum >= target;

            for(int i = mid;i < n && !possible;i++){
                sum += nums[i];
                sum -= nums[i - mid];

                if(sum >= target){
                    possible = true;
                }

            }

            if(possible){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans == n+1 ? 0 : ans;
    }
};