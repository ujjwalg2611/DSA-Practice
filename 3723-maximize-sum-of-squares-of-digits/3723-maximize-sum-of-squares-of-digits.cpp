class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num) return "";
        string ans(num, '0');

        int pos = sum / 9;
        int i = 0;
        while(i < pos){
            ans[i] = 9 + '0';
            i++;
        }

        int rem = sum % 9;
        if(rem > 0){
            ans[i] = rem + '0';
        }

        return ans;
    }
};