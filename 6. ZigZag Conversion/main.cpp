//
//  main.cpp
//  6. ZigZag Conversion
//
//  Created by 于博尧 on 2018/9/12.
//  Copyright © 2018年 于博尧. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include<numeric>

using namespace std;

class Solution{
public:
    string convert(string s, int numRows) {
//        string result;
//        int length = (int)s.size();
//        vector<int> s_line(length, 0);
//        int line = 1;
//        bool flag = true;
//        for(int i = 0; i < length; ++i){
//            s_line[i] = line;
//            if(line == 1)   flag = true;
//            if(line == numRows) flag = false;
//            if(flag == true && line < numRows)    line++;
//            if(flag == false && line > 1)   line--;
//        }
//        for(int j = 1; j <= numRows; ++j){
//            for(int i = 0; i < length; ++i){
//                if((int)s_line[i] == j){
//                    result.push_back(s[i]);
//                }
//            }
//        }
//        return result;
        
        
//        if (numRows == 1) return s;
//        string s1;
//        for (int i=0; i<numRows; i++) {
//            bool even = true;
//            for (int j=i; j<s.size();) {
//                s1 += s[j];
//                cout << s[j] << endl;
//                if (i == 0 || i == numRows-1)
//                    j = j + 2*(numRows - 1);
//                else {
//                    if (even)
//                        j = j + 2*(numRows-i-1);
//                    else
//                        j = j + i*2;
//                    even = !even;
//                }
//            }
//        }
//        return s1;
        
        
        if (s.empty() || numRows < 2) return s;
        vector<string> ret(numRows);
        for (size_t i=0; i<s.size(); ++i) {
            int m = i % (numRows-1), n = (int)i / (numRows-1);
            (n & 0x1 ? ret[numRows-m-1] : ret[m]) += s[i];
        }
        return accumulate(ret.cbegin(), ret.cend(), string());
    }
    
};

int main(int argc, const char * argv[]) {
    Solution S;
    string s = "PAYPALISHIRING";
    string result = S.convert(s, 3);
    cout << result << endl;
    return 0;
}
