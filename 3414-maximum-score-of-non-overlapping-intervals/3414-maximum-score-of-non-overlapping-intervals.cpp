class Solution {
public:
    vector<tuple<int,int,int,int>> a;
    vector<vector<pair<long long, vector<int>>>> dp;
    vector<vector<bool>> vis;
    int n;

    pair<long long, vector<int>> solve(int i, int cnt) {
        if (i == n || cnt == 4)
            return {0, {}};

        if (vis[i][cnt])
            return dp[i][cnt];

        vis[i][cnt] = true;

        auto skip = solve(i + 1, cnt);

        int l = get<0>(a[i]);
        int r = get<1>(a[i]);
        int w = get<2>(a[i]);
        int idx = get<3>(a[i]);

        int next = lower_bound(a.begin() + i + 1, a.end(), r + 1,
            [](const tuple<int,int,int,int>& x, int val) {
                return get<0>(x) < val;
            }
        ) - a.begin();

        auto take = solve(next, cnt + 1);
        take.first += w;
        take.second.push_back(idx);

        sort(take.second.begin(), take.second.end());

        if (take.first > skip.first)
            return dp[i][cnt] = take;

        if (skip.first > take.first)
            return dp[i][cnt] = skip;

        return dp[i][cnt] = min(take, skip);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        a.clear();

        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0],intervals[i][1],intervals[i][2],i});
        }

        sort(a.begin(), a.end(),[](const auto& x, const auto& y) {
            return get<0>(x) < get<0>(y);
        });

        dp.assign(n, vector<pair<long long, vector<int>>>(4));
        vis.assign(n, vector<bool>(4, false));

        return solve(0, 0).second;
    }
};