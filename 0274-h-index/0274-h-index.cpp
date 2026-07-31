class Solution {
public:
    bool possible(int papers,vector<int>& citations) {
        int n = citations.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(citations[i] >= papers) cnt++;
        }
        if(cnt >= papers) return true;
        return false;
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h = 0;
        for(int i=1;i<=n;i++){
            if(possible(i, citations)) h = i;

        }

        return h;

    }
};