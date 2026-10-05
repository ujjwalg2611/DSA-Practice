class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int ans = 0, res = 0;
        stack<char> st;

        for(char ch : s){
            if(ch == '(') {
                st.push(res);
                res = 0;
            } else {
                ans = res;
                res = st.top();
                st.pop();
                
                if(ans == 0) res += 1;
                else {
                    res += 2 * ans;
                }
            }
        }
        return res;
    }
};