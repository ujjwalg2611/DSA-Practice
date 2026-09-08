class Solution {
public:
    int countCommas(int n) {
        if(n < 1e3) return 0;
        return n - 1e3 + 1;
    }
};