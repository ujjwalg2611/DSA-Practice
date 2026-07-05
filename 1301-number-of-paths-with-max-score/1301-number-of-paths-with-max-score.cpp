class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    vector<vector<pair<int,int>>> dp;

    pair<int,int> solve(int i, int j, vector<string>& board) {
        if (i < 0 || j < 0 || board[i][j] == 'X')
            return {-1e9, 0};

        if (board[i][j] == 'E') return {0, 1};

        if (dp[i][j].first != -1) return dp[i][j];

        auto a = solve(i - 1, j, board);
        auto b = solve(i, j - 1, board);
        auto c = solve(i - 1, j - 1, board);

        int mx = max({a.first, b.first, c.first});

        if (mx < 0) return dp[i][j] = {-1e9, 0};

        long long ways = 0;
        if (a.first == mx) ways += a.second;
        if (b.first == mx) ways += b.second;
        if (c.first == mx) ways += c.second;

        int score = mx;
        if (board[i][j] != 'S')
            score += board[i][j] - '0';

        return dp[i][j] = {score, ways % MOD};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        dp.assign(n, vector<pair<int,int>>(n, {-1, -1}));

        auto ans = solve(n - 1, n - 1, board);

        if (ans.second == 0) return {0, 0};

        return {ans.first, ans.second};
    }
};