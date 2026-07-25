class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;
        string s = to_string(n);
        for(char c : s) {
            nums.push_back(c - '0');
        }
        sort(nums.begin(), nums.end());
        int m = nums.size();
        return nums[m-1] * nums[m-2];
    }
};