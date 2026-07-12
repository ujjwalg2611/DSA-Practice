class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};

        vector<int> temp = arr;
        sort(temp.begin(),temp.end());

        unordered_map<int,int> mp;

        int r = 1;
        mp[temp[0]] = r;

        for(int i=1;i<n;i++){
            if(temp[i-1] != temp[i]) {
                r++;
            } 
            mp[temp[i]] = r;
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = mp[arr[i]];
        }

        return ans;
    }
};