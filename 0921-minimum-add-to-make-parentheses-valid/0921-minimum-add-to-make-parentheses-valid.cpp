class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int mini = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                open > 0 ? open-- : mini++;
            }
        }
        return mini + open;
    }
};