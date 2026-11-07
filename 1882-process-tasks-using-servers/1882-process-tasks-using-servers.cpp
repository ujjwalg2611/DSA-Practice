class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> idle;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;

        for(int i = 0; i < n; i++) {
            idle.push({servers[i], i});
        }

        vector<int> ans(m);
        long long t = 0;

        for(int j = 0; j < m; j++) {
            t = max(t, (long long)j);

            while(!busy.empty() && busy.top().first <= t) {
                int idx = busy.top().second;
                busy.pop();
                idle.push({servers[idx], idx});
            }

            if(idle.empty()) {
                t = busy.top().first;

                while(!busy.empty() && busy.top().first <= t) {
                    int idx = busy.top().second;
                    busy.pop();
                    idle.push({servers[idx], idx});
                }
            }

            auto [weight, idx] = idle.top();
            idle.pop();

            ans[j] = idx;

            busy.push({t + tasks[j], idx});
        }

        return ans;
    }
};