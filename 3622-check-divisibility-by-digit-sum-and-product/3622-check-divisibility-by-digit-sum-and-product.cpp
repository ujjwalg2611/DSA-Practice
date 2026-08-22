class Solution {
public:
    bool checkDivisibility(int n) {
        string s = to_string(n);
        int sum = 0, prod = 1;
        for(char c : s){
            sum += c - '0';
            prod *= c - '0';
        }

        return (n % (sum + prod) == 0);
    }
};