class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < n && nums[j] < nums[j + 1]) {
                j++;
            }
            ans = max(ans, j - i + 1);
        }

        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < n && nums[j] > nums[j + 1]) {
                j++;
            }
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};