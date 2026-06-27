class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mpp;
        int ones = 0;
        for(int x : nums){
            if(x == 1) ones++;
            else mpp[x]++;
        }

        int ans = (ones % 2 == 0) ? ones - 1 : ones;

        for(auto &it : mpp){
            long long curr = it.first;
            int cnt = 0;

            while(mpp.count(curr)){
                if(mpp[curr] >= 2) {
                    cnt += 2;
                }
                else {
                    cnt++;
                    break;
                }
                if(curr > LLONG_MAX / curr) break;
                curr = curr * curr;
            }

            if(cnt % 2 == 0) cnt--;

            ans = max(ans,cnt);
        }

        return ans;
    }
};