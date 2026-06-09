#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

			int mini = *min_element(nums.begin(),nums.end());
			int maxi = *max_element(nums.begin(),nums.end());

			long long val = maxi - mini;
			long long tot_sum = k * val;
			return tot_sum;
    }
};


int main() {
						
	return 0;
}

// Problem Link : https://leetcode.com/problems/maximum-total-subarray-value-i/description/?envType=daily-question&envId=2026-06-09