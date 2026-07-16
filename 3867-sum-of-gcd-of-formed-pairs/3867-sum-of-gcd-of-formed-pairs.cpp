class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        int maxi = nums[0];

        for(int i=1;i<n;i++){
            if(nums[i] > maxi) {
                maxi = nums[i];
            }
            pref[i] = gcd(nums[i], maxi);
        }

        sort(pref.begin(), pref.end());

        long long sum = 0;
        int l = 0, r = n-1;
        while(l < r) {
            sum += gcd(pref[l], pref[r]);
            l++;
            r--;
        }

        return sum;
    }
};