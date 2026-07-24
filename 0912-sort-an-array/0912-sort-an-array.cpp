class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<>> pq;
        for(int num : nums) pq.push(num);
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};