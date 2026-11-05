class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;

        sort(arr2.begin(), arr2.end());

        for (int x : arr1) {
            int low = 0, high = arr2.size() - 1;
            bool fl = true;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr2[mid] < x - d) {
                    low = mid + 1;
                }
                else if (arr2[mid] > x + d) {
                    high = mid - 1;
                }
                else {
                    fl = false;
                    break;
                }
            }

            if (fl) ans++;
        }

        return ans;
    }
};