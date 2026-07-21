class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        unordered_map<int,int> mp;
        for(int x : nums) {
            mp[x]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto &[num, cnt] : mp){
            pq.push({cnt, num});
        }

        vector<int> ans;

        while(k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};