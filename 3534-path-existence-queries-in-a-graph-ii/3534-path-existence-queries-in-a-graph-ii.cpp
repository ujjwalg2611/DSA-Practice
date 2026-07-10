class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> sorted(n);
        for(int i=0;i<n;i++){
            sorted[i] = {nums[i],i};
        }

        sort(sorted.begin(),sorted.end());

        vector<int> pos(n);
        for(int i=0;i<n;i++){
            pos[sorted[i].second] = i;
        }

        int LOG = 1;
        while((1<<LOG) < n) LOG++;

        vector<vector<int>> up(n,vector<int>(LOG));

        int r = 0;
        for(int l=0;l<n;l++){
            if(r < l) r = l;
            while(r+1 < n && (sorted[r+1].first - sorted[l].first) <= maxDiff) {
                r++;
            }
            up[l][0] = r;
        }

        for(int j=1;j<LOG;j++){
            for(int i=0;i<n;i++){
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }

        vector<int> ans;

        for(auto &q : queries){
            int src = pos[q[0]];
            int dest = pos[q[1]];

            if(src > dest) swap(src,dest);

            if(src == dest) {
                ans.push_back(0);
                continue;
            }

            int curr = src;
            int hops = 0;
            for(int j=LOG-1;j>=0;j--){
                if(up[curr][j] < dest){
                    curr = up[curr][j];
                    hops += (1<<j);
                }
                
            }
            
            if(up[curr][0] >= dest) {
                ans.push_back(hops + 1);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};