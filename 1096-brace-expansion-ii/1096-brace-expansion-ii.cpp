class Solution {
public:
    set<string> dfs(string &s, int &i) {
        set<string> ans;
        set<string> cur = {""};
        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                for (auto x : cur) ans.insert(x);
                cur = {""};
                i++;
            }
            else if (s[i] == '{') {
                i++; 
                set<string> temp = dfs(s, i);
                set<string> next;
                for (auto a : cur) {
                    for (auto b : temp) {
                        next.insert(a + b);
                    }
                }
                cur = next;
                i++;
            }
            else {
                set<string> next;
                for (auto x : cur) {
                    next.insert(x + s[i]);
                }
                cur = next;
                i++;
            }
        }

        for (auto x : cur) ans.insert(x);

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = dfs(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};