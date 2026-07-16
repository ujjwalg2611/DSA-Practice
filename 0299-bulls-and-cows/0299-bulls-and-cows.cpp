class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        
        int a = 0, b = 0;
        vector<int> cntS(10,0), cntG(10, 0);
        for(int i=0;i<n;i++){
            if(secret[i] == guess[i]) a++;
            else{
                cntS[secret[i] - '0']++;
                cntG[guess[i] - '0']++;
            }
        }

        for(int i=0;i<10;i++){
            b += min(cntS[i], cntG[i]);
        }

        return (to_string(a) + 'A' + to_string(b) + 'B');
        

    }
};