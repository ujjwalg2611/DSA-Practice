class Solution {
public:
    bool check(string s, string word) {
        int n = s.size(), m = word.size();

        for (int i = 0; i + n <= m; i++) {
            int j = 0;
            while (j < n && word[i + j] == s[j]) j++;
            if (j == n) return true;
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;

        for (string &s : patterns) {
            if (check(s, word)) cnt++;
        }

        return cnt;
    }
};