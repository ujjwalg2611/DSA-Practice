class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());
        int n = prices.size();
        int m = discounts.size();

        double ans = 0;

        int i = 0;
        for(;i<min(n,m);i++){
            ans += prices[i] * (100 - discounts[i]) / 100.0;
        }

        while(i<n){
            ans += prices[i];
            i++;
        }
        
        return ans;
    }
};