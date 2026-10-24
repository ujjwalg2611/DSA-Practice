class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> p(1, 0);

        for (int x : m)
            p.push_back(p.back() + x);

        auto day = [&](string s) {
            int month = stoi(s.substr(0, 2));
            int date = stoi(s.substr(3));
            return p[month - 1] + date;
        };

        return max(0, min(day(leaveAlice), day(leaveBob)) - max(day(arriveAlice), day(arriveBob)) + 1);
    }
};