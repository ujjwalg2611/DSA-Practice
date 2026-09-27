class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char> st;
        string ans;
        int i = 0;
        st.push(s[i]);
        i++;
        while(i < n){
            if(s[i] == ')') {
                string temp = "";
                while(!st.empty() && st.top() != '('){
                    temp+=st.top();
                    st.pop();
                }

                st.pop();
                
                for(char c : temp){
                    st.push(c);
                }

            } else {
                st.push(s[i]);
            }

            i++;
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};