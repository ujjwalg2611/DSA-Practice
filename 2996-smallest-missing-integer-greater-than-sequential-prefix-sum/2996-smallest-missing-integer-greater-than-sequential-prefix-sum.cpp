class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        vector<int> hash(51, 0);
        for(int x : nums){
            hash[x]++;
        }

        int seqIdx = 0;
        int lastIdx = 0;

        int i=1;
        while(i < n){
            if(nums[i] == nums[i-1] + 1){
                lastIdx = i;
                
            } else {
                break;
            }
            i++;
        }
        int sum = 0;
        for(int j=seqIdx;j<=lastIdx;j++){
            sum += nums[j];
        }

        if(sum > 50) return sum;

        while(sum <= 50){
            if(hash[sum] == 0) break;
            sum++;
        }
        return sum;
    }
};