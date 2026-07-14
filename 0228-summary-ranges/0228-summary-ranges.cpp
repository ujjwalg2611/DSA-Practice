class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
       
        for(int i=0;i<n;i++){
            int start = nums[i];
            string s = to_string(start);

            int j = start;
            while(i+1 < n && j+1 == nums[i+1]) {
                j = nums[i+1];
                i++;
            }
            
            if(start == j) {
                ans.push_back(s);
            } else {
                ans.push_back(s + "->" + to_string(j));
            }
        }
        return ans;
    }
};