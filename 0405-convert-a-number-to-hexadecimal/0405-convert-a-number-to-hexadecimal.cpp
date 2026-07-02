class Solution {
public:
    
    string toHex(int num) {
        if(num == 0) return "0";

        char hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        
        unsigned int n = num;
        if(n < 0){
            n = ~n + 1;
        } 

        string s = "";
        while(n > 0){
            s += hex[n % 16];
            n /= 16;
        }
        reverse(s.begin(),s.end());

        return s;
    }
};