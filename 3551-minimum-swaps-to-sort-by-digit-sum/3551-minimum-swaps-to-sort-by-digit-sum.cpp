class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 3>> a;

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            a.push_back({sum, nums[i], i});
        }

        sort(a.begin(), a.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[a[i][2]] = i;

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || pos[i] == i) continue;

            int j = i, len = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = pos[j];
                len++;
            }

            swaps += len - 1;
        }

        return swaps;
    }
};