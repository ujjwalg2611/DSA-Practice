class Solution {
public:
    void rotateClockwise(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            rotateClockwise(mat);
            if(mat == target) return true;
        }

        return false;
    }
};