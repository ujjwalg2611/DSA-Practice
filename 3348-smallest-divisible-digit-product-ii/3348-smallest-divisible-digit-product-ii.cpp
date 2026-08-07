class Solution {
public:
    string smallestNumber(string s, long long target) {
        long long check = target;

        for (int d = 2; d <= 9; d++) {
            while (check % d == 0) {
                check /= d;
            }
        }

        if (check != 1) return "-1";

        int len = s.size();
        vector<long long> need(len + 1);

        need[0] = target;
        int zeroIdx = len - 1;

        for (int idx = 0; idx < len; idx++) {
            if (s[idx] == '0') {
                zeroIdx = idx;
                break;
            }
            need[idx + 1] = need[idx] / gcd(need[idx], 1LL * (s[idx] - '0'));
        }

        if (need[len] == 1) return s;

        for (int idx = zeroIdx; idx >= 0; idx--) {
            while (++s[idx] <= '9') {
                long long remaining =
                    need[idx] / gcd(need[idx], 1LL * (s[idx] - '0'));

                int digit = 9;

                for (int j = len - 1; j > idx; j--) {
                    while (remaining % digit != 0) digit--;
                    remaining /= digit;
                    s[j] = char('0' + digit);
                }

                if (remaining == 1) return s;
            }
        }

        string res;

        for (int d = 9; d >= 2; d--) {
            while (target % d == 0) {
                res.push_back(char('0' + d));
                target /= d;
            }
        }

        res.append(max(len + 1 - (int)res.size(), 0), '1');
        reverse(res.begin(), res.end());
        return res;
    }
};