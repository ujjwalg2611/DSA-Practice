class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            string s = "";
            int pow = 0;

            while (x > 0) {
                if (x & 1) {
                    if (pow >= 26) {
                        int cnt = 1 << (pow - 25);
                        s.append(cnt, 'z');
                    } 
                    else {
                        s += char(pow + 'a');
                    }
                }

                x >>= 1;
                pow++;
            }

            reverse(s.begin(), s.end());
            ans.push_back(s);
        }

        return ans;
    }
};