class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = 1LL * n * n;
        long long sumEven = 1LL * 2 * (n * (n-1) / 2);
        
        return gcd(sumEven,sumOdd);
    }
};