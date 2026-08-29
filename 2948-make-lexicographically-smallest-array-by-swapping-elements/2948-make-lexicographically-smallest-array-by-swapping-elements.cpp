class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());

        int currGroup = 0;
        unordered_map<int, int> numToGroup;
        unordered_map<int, list<int>> groupToList;

        numToGroup[numsSorted[0]] = currGroup;
        groupToList[currGroup].push_back(numsSorted[0]);

        for(int i=1;i<n;i++){
            if(numsSorted[i] - numsSorted[i-1] > limit) {
                currGroup++;
            }

            numToGroup[numsSorted[i]] = currGroup;
            groupToList[currGroup].push_back(numsSorted[i]);
        }

        for(int i=0;i<n;i++){
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return nums;
    }
};