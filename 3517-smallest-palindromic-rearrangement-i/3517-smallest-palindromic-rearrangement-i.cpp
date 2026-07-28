class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        
        vector<int> hash(26, 0);
        for(int i=0;i<n/2;i++){
            hash[s[i] - 'a']++;   
        }
    
        string left = "";
        for(int i=0;i<26;i++){
            while(hash[i] > 0){
                left += char(i + 'a');
                hash[i]--;
            }
        }

        int m = left.size();
        string right = left;
        reverse(right.begin(), right.end());

        
        if(n%2==0) return left + right;
        return left + s[n/2] + right;
        
    }
};