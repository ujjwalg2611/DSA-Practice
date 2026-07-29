class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int duplicate, missing;
        vector<int> hash(n+1, 0);
        for(int x : nums){
            hash[x]++;
        }
        for(int i=0;i<=n;i++){
            if(hash[i] == 2) duplicate = i;
            if(hash[i] == 0) missing = i;
        }

        return {duplicate, missing};
    }
};