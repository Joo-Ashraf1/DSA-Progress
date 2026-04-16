using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int size=nums.size();
        for(int option=0;option<(1<<size);option++){
            vector<int> current;
            for(int i=0;i<size;i++){
                if(isOn(option,i)){
                    current.push_back(nums[i]);
                } 

            }
            result.push_back(current);
        }
        return result;

        
    }

    bool isOn(int num,int b){
        return (num>>b)&(1);
    }
};