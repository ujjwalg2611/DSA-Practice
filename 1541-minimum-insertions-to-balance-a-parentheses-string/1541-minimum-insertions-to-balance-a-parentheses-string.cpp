class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        stack<char> st;

        int i = 0;
        while(i < n){
            if(s[i] == '(') {
                st.push(s[i]);
                i++;
            } else {
                if(i+1 < n && s[i+1] == ')') {
                    i += 2;
                } else {
                    ans++;
                    i++;
                }

                if(!st.empty()) {
                    st.pop();
                } else {
                    ans++;
                }
            }

        }

        ans += 2 * st.size();

        return ans;
    }
};