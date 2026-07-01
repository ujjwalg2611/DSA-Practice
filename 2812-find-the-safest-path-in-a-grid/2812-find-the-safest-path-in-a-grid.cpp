class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) q.push({i,j});
            }
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;

            for(int i=0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                    if(grid[nrow][ncol] > 0) continue;

                    grid[nrow][ncol] = grid[row][col] + 1;
                    q.push({nrow,ncol});
                }
            }
        }

        priority_queue<tuple<int,int,int>> pq;
        pq.push({grid[0][0],0,0});
        grid[0][0] = -1;

        while(!pq.empty()){
            auto [sfac, row, col] = pq.top();
            pq.pop();

            if(row == n-1 && col == n-1) return sfac - 1;

            for(int i=0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                    if(grid[nrow][ncol] < 0) continue;

                    int mini = min(sfac,grid[nrow][ncol]);
                    pq.push({mini,nrow,ncol});
                    grid[nrow][ncol] = -1;
                }
            }
        }


        return 0;
    }
};