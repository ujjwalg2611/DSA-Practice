class Solution {
public:
    string result;
    char mid = '$';
    int half;

    bool solve(string &curr, vector<int>& halfFreq, string target, int i, bool greater){
        if(i == half){
            string left = curr;
            string right = left;
            reverse(right.begin(), right.end()); 

            if(mid != '$') left += mid;

            left += right;

            if(left > target){
                result = left;
                return true;
            } 
            
            return false;
        }

        for(int ch = 'a'; ch <= 'z'; ch++){
            if(halfFreq[ch - 'a'] == 0) continue;
            if(greater == false && ch < target[i]) continue;

            curr.push_back(ch);
            halfFreq[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if(solve(curr, halfFreq, target, i+1, isGreater)) return true;

            curr.pop_back();
            halfFreq[ch - 'a']++;

        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a']++;
        }

        int odd = 0;
        
        for(int i=0;i<26;i++){
            if(freq[i] == 0) continue;
            if(freq[i]%2){
                odd++;
                mid = i + 'a'; 
            }
            freq[i] = freq[i] / 2;
        }

        if(odd > 1) return "";

        half = n / 2;

        bool greater = false;
        string curr = "";
        solve(curr, freq, target, 0, greater);

        return result;
    }
};