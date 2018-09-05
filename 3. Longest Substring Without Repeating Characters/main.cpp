//
//  main.cpp
//  3. Longest Substring Without Repeating Characters
//
//  Created by 于博尧 on 2018/9/4.
//  Copyright © 2018年 于博尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(256, -1);
        int maxlen = 0;
        int start = -1;
        for(int i = 0; i < s.size(); ++i){
            if(m[s[i]] > start){
                start = m[s[i]];
            }
            m[s[i]] = i;
            maxlen = max(maxlen, i - start);
        }
        return maxlen;
    }
};

int main(int argc, const char * argv[]) {
    Solution S;
    string s = "pwwkew";
    int length = S.lengthOfLongestSubstring(s);
    cout << length << endl;
    return 0;
}
