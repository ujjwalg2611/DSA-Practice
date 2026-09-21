class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);
        vector<long long> cnt(k);
        for (int x : nums) {
            vector<long long> next(k);
            next[x % k]++;
            for (int r=0;r<k;r++) {
                if (cnt[r]) {
                    next[(1LL * r * x) % k] += cnt[r];
                }
            }
            for (int r=0;r<k;r++) {
                ans[r] += next[r];
            }
            cnt = next;
        }

        return ans;
    }
};