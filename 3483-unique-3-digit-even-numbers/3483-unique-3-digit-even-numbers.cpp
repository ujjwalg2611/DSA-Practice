class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> st;
        
        for(int i=0;i<n;i++){
            if(digits[i] == 0) continue;
            long long num = 0;
            num = num * 10 + digits[i];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                num = num * 10 + digits[j];
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue;
                    num = num * 10 + digits[k];

                    if(num%2==0) st.insert(num);
                    num /= 10;
                }
                num /= 10;
            }
        }

        return st.size();
    }
};