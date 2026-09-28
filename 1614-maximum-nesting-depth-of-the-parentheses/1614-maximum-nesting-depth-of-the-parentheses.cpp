class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int maxi = 0;
        stack<char> st;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '(') {
                st.push(s[i]);
                cnt++;
                maxi = max(maxi,cnt);
            }
            else if(s[i] == ')') {
                st.pop();
                cnt--;
            }

        }

        return maxi;
    }
};