class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }

        for(int i=0;i<n;i++){
            ans[i] = adj[i].size();
        }

        return ans;
    }
};