class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        string s = to_string(n);
        string temp = "";
        long long sum = 0;
        for(char digit : s){
            if(digit == '0') continue;
            else{
                temp += digit;
                sum += digit - '0';
            }
        }

        x = (temp.size() == 0) ? 0 : stoi(temp);

        long long ans = x * sum;

        return ans;
    }
};