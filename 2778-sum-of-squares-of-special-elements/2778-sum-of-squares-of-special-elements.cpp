class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int j = i+1;
            if(n % j == 0){
                long long prod = nums[i] * nums[i];
                ans += (int)prod;
            }
        }

        return ans;
    }
};