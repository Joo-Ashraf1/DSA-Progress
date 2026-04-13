#include <vector>
#include <climits>
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n= INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                n=min(abs(i-start),n);

            }


        }
        return n;
        
    }
};