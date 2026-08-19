class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;
        for(auto r : reservedSeats){
            int row = r[0];
            int col = r[1];

            if(col >= 2 && col <= 5) mp[row].insert(0);
            if(col >= 4 && col <= 7) mp[row].insert(1);
            if(col >= 6 && col <= 9) mp[row].insert(2);

        }

        long long ans = 2 * n;

        for(auto &[row, groups] : mp){
            if(groups.size() == 3){
                ans -= 2;
            } else {
                ans -= 1;
            }
        }

        return ans;
    }
};