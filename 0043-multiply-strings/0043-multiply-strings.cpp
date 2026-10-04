class Solution {
public:
    string multiply(string num1, string num2) {
       if(num1 == "0" || num2 == "0") return "0";

       reverse(num1.begin(), num1.end());
       reverse(num2.begin(), num2.end());

       string ans = "";
       
       for(int i=0;i<num1.size();i++){
        string temp = "";
        int carry = 0;

        for(char c : num2){
            long long prod = (num1[i] - '0') * (c - '0') + carry;
            temp += (prod % 10) + '0';
            carry = (prod / 10);
        }

        if(carry) temp += carry + '0';

        for(int j=0;j<i;j++){
            temp = '0' + temp;
        }

        reverse(temp.begin(), temp.end());

        if(ans.empty()) {
            ans = temp;
        } else {
            int carry = 0;
            string sum = "";
            int p = ans.size() - 1, q = temp.size() - 1;

            while(p >= 0 || q >= 0 || carry) {
                int digit = carry;

                if(p >= 0) digit += ans[p--] - '0';
                if(q >= 0) digit += temp[q--] - '0';

                sum += (digit % 10) + '0';
                carry = digit / 10;
            }

            reverse(sum.begin(), sum.end());

            ans = sum;

        }

       }

        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;

        return i == ans.size() ? "0" : ans.substr(i);
    }
};