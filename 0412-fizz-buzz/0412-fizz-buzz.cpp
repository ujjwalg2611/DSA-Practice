class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            int num = i + 1;
            if(num % 3 == 0 && num % 5 == 0) {
                ans[i] = "FizzBuzz";
                continue;
            }
            if(num % 3 == 0 && num % 5){
                ans[i] = "Fizz";
                continue;
            }
            if(num % 3 && num % 5 == 0) {
                ans[i] = "Buzz";
                continue;
            }

            ans[i] = to_string(num); 
        }
        return ans;
    }
};