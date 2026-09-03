class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();

        vector<long long> pref(n+1, 0);
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1] + damage[i-1];
        }

        long long score = 0;
        for(int i=1;i<=n;i++){
            long long need = pref[i] + requirement[i-1] - hp;

            int k = lower_bound(pref.begin(),pref.begin() + i,need) - pref.begin();

            score += i - k;
        }

        return score;
    }
};