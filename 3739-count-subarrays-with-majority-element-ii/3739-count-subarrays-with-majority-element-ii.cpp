class Solution {
public:
    long long ans;
    void mergeSort(vector<int>& pref, int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        mergeSort(pref, l, mid);
        mergeSort(pref, mid + 1, r);

        int i = l;
        for (int j = mid + 1; j <= r; j++) {
            while (i <= mid && pref[i] < pref[j]) i++;
            ans += (i - l);
        }

        vector<int> temp;
        int p1 = l, p2 = mid + 1;

        while (p1 <= mid && p2 <= r) {
            if (pref[p1] <= pref[p2]) temp.push_back(pref[p1++]);
            else temp.push_back(pref[p2++]);
        }

        while (p1 <= mid) temp.push_back(pref[p1++]);
        while (p2 <= r) temp.push_back(pref[p2++]);

        for (int k = l; k <= r; k++){
            pref[k] = temp[k - l];
        }
            
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            if(nums[i] == target) arr[i] = 1;
            else arr[i] = -1;
        }

        vector<int> pref(n+1);
        pref[0] = 0;
        for(int k=1;k<=n;k++){
            pref[k] = pref[k-1] + arr[k-1];
        }

        
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<=n;j++){
        //         if(pref[j] > pref[i]) cnt++;
        //     }
        // }

        mergeSort(pref,0,n);

        return ans;

    }
};