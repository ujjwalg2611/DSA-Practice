class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.size();
        vector<int> hash(26, 0);

        for(int i=0;i<n;i++){
            hash[s[i] - 'a']++;
        }
        int prev = 0;
        for(int i=0;i<26;i++){
            if(hash[i] == 0) continue;
            if(prev > 0) {
                if(prev != hash[i]) return false;
            } else {
                prev = hash[i];
            }
        }

        return true;
    }
};