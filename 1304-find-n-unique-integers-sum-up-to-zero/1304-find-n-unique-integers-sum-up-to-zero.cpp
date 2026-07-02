class Solution {
public:
    vector<int> sumZero(int n) {
        int temp = n;
        temp = temp / 2;
        vector<int> ans;
        while(temp > 0) {
            ans.push_back(temp);
            ans.push_back(-1*temp);
            temp--;
        }
        if(n%2){
            ans.push_back(0);
            return ans;
        }
        return ans;
    }
};