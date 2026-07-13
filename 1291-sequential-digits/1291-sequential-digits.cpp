class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        
        int minlen = to_string(low).length();
        int maxlen = to_string(high).length();

        vector<int> ans;

        for(int i=minlen;i<=maxlen;i++){
            for(int j=0;j+i<=9;j++){
                string sub = s.substr(j,i);
                int num = stoi(sub);
                if(num >= low && num <= high) ans.push_back(num);
            }
        }

        return ans;

    }
};