//
//  main.cpp
//  7. Reverse Integer
//
//  Created by 于博尧 on 2018/9/13.
//  Copyright © 2018年 于博尧. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    int reverse(int x) {
        long long ret = 0;
        while (x) {
            ret = ret * 10 + (x % 10);
            x = x / 10;
        };
        if (ret > INT_MAX || ret < INT_MIN) return 0;
        return (int)ret;
    }
};


int main(int argc, const char * argv[]) {
    Solution S;
    int num = 1534236469;
    int result = S.reverse(num);
    cout << result << endl;
    return 0;
}
