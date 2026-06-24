class Solution {
public: 
    const int MOD = 1e9 + 7;
    vector<vector<int>> matrixExp(vector<vector<int>>& base,int e,int m){
        vector<vector<int>> res(m,vector<int>(m));
        for(int i=0;i<m;i++){
            res[i][i] = 1;
        }
        while(e > 0){
            if(e % 2 == 1){
                res = mul(res,base);
            }
            base = mul(base,base);
            e = e >> 1;
        }

        return res;
    }
    vector<vector<int>> mul(vector<vector<int>>& A,vector<vector<int>>& B){
        int m = A.size();
        vector<vector<int>> C(m,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                long long sum = 0;
                for(int k=0;k<m;k++){
                    sum = (sum + 1LL * A[i][k] * B[k][j]) % MOD;
                }
                C[i][j] = sum;
            }
        }

        return C;
    }
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<vector<int>> M(m,vector<int>(m));
        for(int j=0;j<m;j++){
            for(int i=m-j;i<m;i++){
                M[i][j] = 1;
            }
        }

        vector<vector<int>> powM = matrixExp(M,n-1,m);

        long long ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                ans = (ans + powM[i][j]) % MOD;
            }
        }

        return (int)(ans * 2 % MOD);
    }
};