class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
    
        int len = 2*n + 2;
        vector<long long> countAtSum(len,0);
        vector<long long> cumulativeCount(len,0);

        int idx = n+1;
        countAtSum[idx] = 1;
        cumulativeCount[idx] = 1;

        long long ans = 0;
        for(int num : nums){
            if(num == target) idx++;
            else idx--;

            countAtSum[idx]++;
            ans += cumulativeCount[idx - 1];
            cumulativeCount[idx] = cumulativeCount[idx - 1] + countAtSum[idx];
        }

        return ans;

    }
};