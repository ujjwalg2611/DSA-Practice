class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int maxlen = 0;

        int l=0, r=0;
        while(r < n){
            while(mp[s[r] - 'a'] >= 2){
                mp[s[l] - 'a']--;
                l++;
            }

            if(mp[s[r] - 'a'] < 2){
                mp[s[r] - 'a']++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};