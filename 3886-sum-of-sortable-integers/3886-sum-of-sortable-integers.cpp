class Solution {
public:
    vector<int> prefMax, suffMin, prefDrop;

    bool check(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i += k) {
            int j = i + k - 1;

            int drops = prefDrop[j] - prefDrop[i];

            if (nums[j] > nums[i]) {
                drops++;
            }

            if (drops > 1 || prefMax[i] > suffMin[i]) {
                return false;
            }
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        prefMax.assign(n + 1, 0);
        suffMin.assign(n + 1, INT_MAX);
        prefDrop.assign(n, 0);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1] + (nums[i - 1] > nums[i]);
        }

        int ans = 0;

        for (int k = 1; k <= n / k; k++) {
            if (n % k == 0) {
                if (check(nums, k)) {
                    ans += k;
                }

                int other = n / k;

                if (other != k && check(nums, other)) {
                    ans += other;
                }
            }
        }

        return ans;
    }
};