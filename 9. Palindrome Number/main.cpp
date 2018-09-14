//
//  main.cpp
//  9. Palindrome Number
//
//  Created by 于博尧 on 2018/9/14.
//  Copyright © 2018年 于博尧. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    bool isPalindrome(int x) {
        long x_x = 0;
        long x_origin = (long)x;
        if(x < 0) return false;
        else if(x == 0) ;
        else{
            while(x){
                x_x = x_x*10 + x%10;
                x = x/10;
            }
            if(x_x != x_origin) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution S;
    int num = 121;
    bool result = S.isPalindrome(num);
    cout << result << endl;
    return 0;
}
