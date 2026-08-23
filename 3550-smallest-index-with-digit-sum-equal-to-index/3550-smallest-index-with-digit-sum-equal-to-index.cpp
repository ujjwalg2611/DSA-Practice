class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            int sum = 0;
            for(char c : s){
                sum += c - '0';
            }
            if(sum == i) ans = min(ans, i);
        }
        return ans == n ? -1 : ans;
    }
};