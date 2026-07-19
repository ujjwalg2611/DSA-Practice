class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> vis(26, false);

        for(char &c : s) {
            freq[c - 'a']++;
        }
        
        stack<char> st;
        for(char &c : s) {
            int x = c - 'a';
            freq[x]--;
            
            if(vis[x]) continue;

            while(!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0) {
                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            vis[x] = true;
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};