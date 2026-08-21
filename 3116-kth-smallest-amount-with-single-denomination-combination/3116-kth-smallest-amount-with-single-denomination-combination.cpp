class Solution {
public:
    using ll = long long;
    bool check(ll mid, vector<int>& coins, int k){
        int n = coins.size();
        ll cnt = 0;
        for(int i = 1;i < 1 << n;i++){
            ll v = 1;
            for(int j=0;j<n;j++){
                if(i >> j & 1){
                    v = lcm(v, coins[j]);

                    if(v > mid) break;
                }
            }

            int m = __builtin_popcount(i);
            if(m % 2){
                cnt += mid / v;
            } else {
                cnt -= mid / v;
            }

        }

        return cnt >= k;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        ll low = 1, high = 1e11;
        while(low < high){
            ll mid = low + (high - low) / 2;
            if(check(mid,coins,k)){
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;

    }
};