class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        // vector<pair<int,int>> store;
        bool fl = true;
        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            if(nums1[i] % 2){
                // store.push_back({nums1[i], i});
                fl = false;
                mini = min(mini, nums1[i]);
            }
        }

        if(fl) return true;

        for(int i=0;i<n;i++){
            if(nums1[i]%2) continue;

            // for(int j=0;j<store.size();j++){
            //     if(i != store[j].second && nums1[i] - store[j].first >= 1) {
            //         nums1[i] = nums1[i] - store[j].first;
            //         break;
            //     }
            // }

            if(nums1[i] - mini >= 1) nums1[i] = nums1[i] - mini;

            if(nums1[i]%2 == 0) return false;
        }

        return true;
    }
};