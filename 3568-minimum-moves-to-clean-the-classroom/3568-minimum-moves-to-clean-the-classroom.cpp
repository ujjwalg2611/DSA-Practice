class Solution {
public:
    bool isValid(int row, int col, int m, int n){
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> id(m, vector<int>(n, -1));

        int sr = -1, sc = -1;
        int litter = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if(classroom[i][j] == 'L') {
                    id[i][j] = litter++;
                }
            }
        }

        if(litter == 0) return 0;

        int totalMask = (1 << litter) - 1;

        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>((1 << litter), -1)));
        best[sr][sc][0] = energy;

        queue<tuple<int, int, int, int, int>> q;
        q.push({0, energy, sr, sc, 0});

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [steps, remEnergy, row, col, mask] = q.front();
            q.pop();

            if(mask == totalMask) return steps;

            for(int i=0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(!isValid(nrow, ncol, m, n)) continue;
                if(classroom[nrow][ncol] == 'X') continue;
                if(remEnergy == 0) continue;

                int newEnergy = remEnergy - 1;
                int newMask = mask;

                if(classroom[nrow][ncol] == 'L'){
                    newMask |= (1 << id[nrow][ncol]);
                }
                if(classroom[nrow][ncol] == 'R'){
                    newEnergy = energy;
                } 

                if(best[nrow][ncol][newMask] >= newEnergy) continue;

                best[nrow][ncol][newMask] = newEnergy;

                q.push({steps + 1, newEnergy, nrow, ncol, newMask});
                
            }
        }
        return -1;
    }
};