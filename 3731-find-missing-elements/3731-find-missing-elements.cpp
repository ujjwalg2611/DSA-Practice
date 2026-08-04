class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int num = nums[0];
        for(int i=1;i<n;i++){
            if(num + 1 == nums[i]) {
                num = nums[i];
                continue;
            }
            while(num + 1 < nums[i]){
                ans.push_back(num + 1);
                num++;
            }
            num = nums[i];
        }

        return ans;
    }
};