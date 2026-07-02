class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = to_string(n);
        int sum = 0;
        int prod = 1;
        for(char ch : s){
            sum = sum + (ch - '0');
            prod = prod * (ch - '0');
        }

        return prod - sum;
    }
};