class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        for(int i=0;i<n;i++) {
            vector<int> hash(n+1, 0);
            for(int j=0;j<n;j++) {
                if(board[i][j] == '.') continue;
                hash[board[i][j] - '0']++;

                if(hash[board[i][j] - '0'] > 1) return false;
            }
        }

        for(int j=0;j<n;j++) {
            vector<int> hash(n+1, 0);
            for(int i=0;i<n;i++) {
                if(board[i][j] == '.') continue;
                hash[board[i][j] - '0']++;

                if(hash[board[i][j] - '0'] > 1) return false;
            }
        }

        for(int row = 0; row < n; row+=3) {
            for(int col = 0; col < n; col+=3) {

                vector<int> hash(n+1, 0);

                for(int i=row;i<row+3;i++) {
                    for(int j=col;j<col+3;j++) {
                        if(board[i][j] == '.') continue;
                        hash[board[i][j] - '0']++;

                        if(hash[board[i][j] - '0'] > 1) return false;
                    }
                }
            }
        }

        return true;
    }
};