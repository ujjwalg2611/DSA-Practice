class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int cnt = 0;
        string ans = "";

        int l = 0, r = 0;
        while(r < n){
            if(s[r] == '1'){
                cnt++; 
            } 

            while(cnt > k){
                if(s[l] == '1') cnt--;
                l++;
            }

            if(cnt == k){
                while(s[l] == '0') {
                    l++;
                }

                string curr = s.substr(l, r - l + 1);

                if(ans == "" || curr.size() < ans.size() || 
                (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }

            r++;
        }

        return ans;
    }
};