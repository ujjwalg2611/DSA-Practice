class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int m = n / 8;
        int rem = n % 8;

        return 8 * (m * (m + 1) / 2) + (m + 1) * rem;
    }
};