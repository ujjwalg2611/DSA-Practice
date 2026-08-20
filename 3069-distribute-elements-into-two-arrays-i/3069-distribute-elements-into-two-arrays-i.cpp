class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        stack<int> s1, s2;
        s1.push(nums[0]);
        s2.push(nums[1]);

        for(int i=2;i<n;i++){
            if(s1.top() > s2.top()) {
                s1.push(nums[i]);
            }else {
                s2.push(nums[i]);
            }
        }

        vector<int> arr1, arr2;
        while(!s1.empty()){
            arr1.push_back(s1.top());
            s1.pop();
        }
        reverse(arr1.begin(), arr1.end());

        while(!s2.empty()){
            arr2.push_back(s2.top());
            s2.pop();
        }
        reverse(arr2.begin(), arr2.end());

        for(int i=0;i<arr2.size();i++){
            arr1.push_back(arr2[i]);
        }

        return arr1;
    }
};