class Solution {
public:
    int smallestNumber(int n, int t) {
        int i = n;
        while(i <= n + 10){
            string s = to_string(i);
            int prod = 1;
            for(char &ch : s){
                prod *= (ch - '0');
            }
            if(prod%t == 0) break;
            i++;
        }

        return i;
    }
};