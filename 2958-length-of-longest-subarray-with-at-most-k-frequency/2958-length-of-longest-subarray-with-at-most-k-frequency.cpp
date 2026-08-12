class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxlen = 0;
        int l = 0,r = 0;
        while(r < n){
            while(mp[nums[r]] >= k) { 
                mp[nums[l]]--;
                l++;
            } 
            if(mp[nums[r]] < k) {
                mp[nums[r]]++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};