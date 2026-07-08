class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<ll> pref(n+1,0),conval(n+1,0),pow10(n+1,1);
        vector<int> count(n+1,0);
        
        for(int i=1;i<=n;i++){
            int num = s[i - 1] - '0';

            pref[i] = (pref[i-1] + num) % MOD;

            if(num == 0){
                conval[i] = conval[i-1];
                count[i] = count[i-1];
            } else {
                conval[i] = (conval[i-1] * 10 + num) % MOD;
                count[i] = count[i-1] + 1;
            }
            
        }

        for(int i=1;i<=n;i++){
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        vector<int> ans;

        for(auto &q : queries){
            int left = q[0], right = q[1];

            ll sum = (pref[right + 1] - pref[left] + MOD) % MOD;

            ll leftPart = conval[left];
            ll rightPart = conval[right + 1];

            int diff = count[right + 1] - count[left];

            ll range = (rightPart - ((leftPart * pow10[diff]) % MOD) + MOD) % MOD;

            ans.push_back((range * sum) % MOD);
 


        }

        return ans;
    }
};