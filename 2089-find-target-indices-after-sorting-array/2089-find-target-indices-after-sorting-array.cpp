class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt0 = 0;
        int cnt1 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < target) cnt0++;
            else if(nums[i] == target) cnt1++;
        }
        vector<int> ans;
        for(int i=cnt0;i<cnt0+cnt1;i++){
            ans.push_back(i);
        }

        return ans;
    }
};