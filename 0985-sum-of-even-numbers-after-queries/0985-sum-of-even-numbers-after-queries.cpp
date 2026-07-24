class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans;

        int total = 0;
        for(int x : nums) {
            if(x%2==0) total += x;
        }

        for(auto &q : queries) {
            int val = q[0];
            int idx = q[1];
            int temp = nums[idx];
            nums[idx] = nums[idx] + val;
            if(nums[idx]%2==0) { 
                total += nums[idx];
            }
            if(temp%2==0) {
                total -= temp;
            }
            ans.push_back(total);
        }

        return ans;
    }
};