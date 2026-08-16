class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dup = mat;
        k = k % n;
        bool fl = true;
        while(k > 0){
            for(int i=0;i<m;i++){
                if(fl){
                    
                    for(int j=0;j<n-1;j++){
                        swap(dup[i][j],dup[i][j+1]);
                    }
                    
                } else {
                    
                    for(int j=1;j<n;j++){
                        swap(dup[i][j-1],dup[i][j]);
                    }
                }
                fl = !fl;
            }
            k--;
        }

        return dup == mat;

    }
};