class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());

        vector<long long> freq(mx + 1, 0);
        for(int x : nums) freq[x]++;

        vector<long long> gcdPairs(mx + 1,0);
        for(int i=1;i<=mx;i++) {
            long long cnt = 0;
            for(int j=i;j<=mx;j+=i) {
                cnt += freq[j];
            }
            gcdPairs[i] = cnt * (cnt - 1) / 2;
        }

        for(int i=mx;i>=1;i--) {
            for(int j=2*i;j<=mx;j+=i) {
                gcdPairs[i] -= gcdPairs[j];
            }
        }

        vector<long long> pref(mx+1, 0);
        pref[0] = gcdPairs[0];
        for(int i=1;i<=mx;i++) {
            pref[i] = pref[i-1] + gcdPairs[i];
        }

        vector<int> ans;
        for(long long q : queries) {
            long long k = q + 1;
            int l = 1, r = mx;
            while(l < r) {
                int mid = l + (r - l) / 2;
                if(pref[mid] >= k) r= mid;
                else l = mid + 1;
            }
            ans.push_back(l);
        }

        return ans;
    }
};