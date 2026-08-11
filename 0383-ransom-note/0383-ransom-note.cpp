class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) return false;

        vector<int> hash(26, 0);
        
        for(char c : magazine){
            hash[c - 'a']++;
        }

        for(char c : ransomNote){
            hash[c - 'a']--;
            if(hash[c - 'a'] < 0) return false;
        }

        return true;
        
    }
};