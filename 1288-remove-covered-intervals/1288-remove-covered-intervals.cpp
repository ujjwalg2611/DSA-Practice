class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int cnt = 0;
        int maxEnd = -1;

        for (auto &it : intervals) {
            if (it[1] > maxEnd) {
                cnt++;
                maxEnd = it[1];
            }
        }

        return cnt;
    }
};