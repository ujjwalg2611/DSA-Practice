class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for(int stone : stones) pq.push(stone);
        while(!pq.empty()) {

            if(pq.size() == 1) return pq.top();

            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x == y) continue;
            if(y > x) {
                pq.push(y - x);
            }
        } 

        return 0;
    }
};