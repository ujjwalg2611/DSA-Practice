class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int x : nums) st.insert(x);
        int ans = k;
        while(st.count(ans)){
            ans += k;
        }

        return ans;
    }
};