class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();

        string ans(n + m, '0');

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int prod = (num1[i] - '0') * (num2[j] - '0');
                int sum = prod + (ans[i+j+1] - '0');

                ans[i+j+1] = (sum % 10) + '0';
                ans[i+j] += (sum / 10);
            }
        }

        int i=0;
        while(i < ans.size() && ans[i] == '0') i++;

        return ans.substr(i);
    }
};