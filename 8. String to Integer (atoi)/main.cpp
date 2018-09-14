//
//  main.cpp
//  8. String to Integer (atoi)
//
//  Created by 于博尧 on 2018/9/14.
//  Copyright © 2018年 于博尧. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    int myAtoi(string str) {
//        long long res = 0;
//        int count = 0;
//        bool flag_space = true;
//        bool flag_sign = true;
//        bool nagetive = false;
//        bool ismax = false;
//        bool begin_zero = true;
//        for(int i = 0; i < (int)str.length(); ++i){
//            if((int)str[i] == 32 && flag_space)
//                continue;
//            else if((int)str[i] == 32 && !flag_space){
//                break;
//            }
//            else if((int)str[i] >= 48 && (int)str[i] <= 57){
//                res = res*10 + (int)str[i] - 48;
//                flag_space = false;
//                flag_sign = false;
//                //cout << res << endl;
//                if(begin_zero == true && (int)str[i] == 48)
//                    ;
//                else{
//                    begin_zero = false;
//                    count++;
//                }
//                if(count > 10){
//                    ismax = true;
//                    break;
//                }
//            }
//            else if((int)str[i] == 43 && flag_sign){
//                flag_sign = false;
//                flag_space = false;
//            }
//            else if((int)str[i] == 45 && flag_sign){
//                nagetive = true;
//                flag_sign = false;
//                flag_space = false;
//            }
//            else{
//                break;
//            }
//        }
//        if(ismax && nagetive)
//            return INT_MIN;
//        if(ismax && !nagetive)
//            return INT_MAX;
//        res = nagetive ? res*(-1) : res;
//        if(res > INT_MAX)
//            return INT_MAX;
//        if(res < INT_MIN)
//            return INT_MIN;
//        return (int)res;
    
        if (str.length() < 1) return 0;
        int i = 0;
        if (str[i] < '0' && str[i] > '9' && str[i] != ' ' && str[i] != '-' && str[i] != '+') return 0;
        while (i < str.length() && str[i] == ' ') i++;
        if (i == str.length()) return 0;
        bool negative = false;
        //optional sign
        if (str[i] == '-'){
            negative = true;
            i++;
        }
        else if (str[i] == '+')
            i++;
        long int num = 0; //, cnt = 0;
        while (i < str.length() && str[i] >= '0' && str[i] <= '9'){
            num = num * 10 + (str[i++] - '0');
            if (num > INT_MAX) return negative ? INT_MIN : INT_MAX;
        }
        return negative ? (-1 * (int)num) : (int)num;
    }
};

int main(int argc, const char * argv[]) {
    Solution S;
    string s = "-  234";
    int result = S.myAtoi(s);
    cout << result << endl;
    return 0;
}
