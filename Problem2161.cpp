#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> low,high;
        int sameCnt = 0;
        for(auto &num : nums){
            if(num < pivot) low.push_back(num);
            else if(num > pivot) high.push_back(num);
            else sameCnt++;
        }
        vector<int> res;
        for(auto &val : low){
            res.push_back(val);
        }
        while(sameCnt > 0){
            res.push_back(pivot);
            sameCnt--;
        }

        for(auto &val : high){
            res.push_back(val);
        }

        return res;
    }
};

int main(){

	return 0;
}


// Problem link : https://leetcode.com/problems/partition-array-according-to-given-pivot/?envType=daily-question&envId=2026-06-08