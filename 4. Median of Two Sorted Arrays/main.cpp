//
//  main.cpp
//  4. Median of Two Sorted Arrays
//
//  Created by 于博尧 on 2018/9/6.
//  Copyright © 2018年 于博尧. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0.0;
        int num[5000] = {0};
        int pos = 0;
        int i = 0, j = 0;
        while(pos < nums1.size() + nums2.size()){
            if(i == nums1.size()){
                num[pos] = nums2[j++];
            }
            else if(j == nums2.size()){
                num[pos] = nums1[i++];
            }
            else if(nums1[i] < nums2[j]){
                num[pos] = nums1[i++];
            }
            else{
                num[pos] = nums2[j++];
            }
            pos++;
        }
        if(pos % 2 == 1){
            result = num[pos/2];
        }
        else{
            result = (double)(num[pos/2] + num[pos/2-1]) / 2.0;
        }
        return result;
    }
};




int main(int argc, const char * argv[]) {
    Solution S;
    vector<int> nums1 = {3};
    vector<int> nums2 = {-2, -1};
    double result = S.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}
