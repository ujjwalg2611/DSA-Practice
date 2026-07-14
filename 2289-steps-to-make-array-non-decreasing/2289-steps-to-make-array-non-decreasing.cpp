class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>> st;
        int ans = 0;

        for(int x : nums){
            int step = 0;
            while(!st.empty() && st.top().first <= x){
                step = max(step, st.top().second);
                st.pop();
            }

            if(st.empty()) step = 0;
            else step++;

            ans = max(ans,step);
            st.push({x,step});
        }

        return ans;
    }
};