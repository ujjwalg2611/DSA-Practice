class Solution {
public:
    string convertBinary(int n){
        string s = "";
        while(n > 0){
            s += char('0' + n%2);
            n /= 2;
        }
        if(s.size() < 32){
            while(s.size() < 32)  s += '0';
        }

        reverse(s.begin(), s.end());
        return s; 
    }
    int convertDecimal(string &s){
        int n = 0;
        for(int i=31;i>=0;i--){
            n += (s[i] - '0') * (1 << (31 - i));
        }
        return n;
    }
    int reverseBits(int n) {
        string s = convertBinary(n);
        reverse(s.begin(), s.end());
        int ans = convertDecimal(s);

        return ans;

    }
};