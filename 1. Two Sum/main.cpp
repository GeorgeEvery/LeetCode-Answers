//
//  main.cpp
//  1. Two Sum
//
//  Created by 于博尧 on 2018/9/2.
//  Copyright © 2018年 于博尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    // Time:  O(n^2)
    // Space: O(1)
    vector<int> twoSum_doublecycle(vector<int> &nums, int target){
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
    
    // TIme:  O(1)
    // Space: O(n)
    vector<int> twoSum_map(vector<int> &nums, int target){
        vector<int> result;
        unordered_map<int, int> mymap;
        for(int i = 0; i < nums.size(); ++i){
            mymap.insert(make_pair(nums[i], i));
        }
        for(int i = 0; i < nums.size(); ++i){
            //unordered_map<int, int>::iterator got = mymap.find(target - nums[i]);
            if(mymap.find(target - nums[i]) != mymap.end()){
                int index = mymap[target - nums[i]];
                if(index == i)
                    continue;
                else{
                    result.push_back(i);
                    result.push_back(index);
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
    //vector<int> result = S.twoSum_doublecycle(test_data, target);
    vector<int> result = S.twoSum_map(test_data, target);
    if(result.size() > 0){
        for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    else
        cout << "No Matches!" << endl;
    return 0;
}
