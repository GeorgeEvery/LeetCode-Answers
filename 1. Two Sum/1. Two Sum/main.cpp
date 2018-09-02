//
//  main.cpp
//  1. Two Sum
//
//  Created by 于博尧 on 2018/9/2.
//  Copyright © 2018年 于博尧. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        vector<int> result;
        for(int i = 0; i < nums.size() - 1; ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution S;
    vector<int> test_data = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = S.twoSum(test_data, target);
    if(result.size() > 0){
        for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    else
        cout << "No Matches!" << endl;
    return 0;
}
