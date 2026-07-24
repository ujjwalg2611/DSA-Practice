class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> pairXor;
        unordered_set<int> ans;

        for (int x : nums) ans.insert(x);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        for (int p : pairXor) {
            for (int x : nums) {
                ans.insert(p ^ x);
            }
        }

        return ans.size();
    }
};