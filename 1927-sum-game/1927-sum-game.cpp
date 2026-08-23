class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int lques = 0, rques = 0;
        int lsum = 0, rsum = 0;

        for(int i=0;i<n;i++){
            if(i < n / 2) {
                if(num[i] == '?') lques++;
                else lsum += (num[i] - '0');
                
            } else  {
                if(num[i] == '?') rques++;
                else rsum += (num[i] - '0');

            }
        }

        if((lques + rques) % 2 == 1) return true;

        return lsum - rsum != 9 * (rques - lques) / 2;

    }
};