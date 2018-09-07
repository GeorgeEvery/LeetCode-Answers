//
//  main.cpp
//  5. Longest Palindromic Substring
//
//  Created by 于博尧 on 2018/9/6.
//  Copyright © 2018年 于博尧. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution{
    
    // basic method
    // Time: O(n*n)
//private:
//    void expand(string s, int pos_start, int pos_end, int &start, int& end){
//        while(pos_start >= 0 && pos_end <= s.size() && s[pos_start] == s[pos_end]){
//            pos_start--;
//            pos_end++;
//        }
//        pos_start++;
//        pos_end--;
//        if(pos_end - pos_start > end - start){
//            start = pos_start;
//            end = pos_end;
//            //cout << start << " " << end << endl;
//        }
//    }
//
//public:
//    string longestPalindrome(string s) {
//        int start = 0;
//        int end = 0;
//        for(int pos = 0; pos < s.size(); ++pos){
//            expand(s, pos, pos, start, end);
//            expand(s, pos, pos + 1, start, end);
//            //cout << "pos = " << pos << endl;
//        }
//        //cout << endl << start << " " << end << endl;
//        return s.substr(start, end - start + 1);
//    }
    
    // Manacher's Algorithm
    // Time: O(n)
public:
    string longestPalindrome(string s) {
        string t ="$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += '#';
        }
        cout << t << endl;
        vector<int> p(t.size(), 0);
        int id = 0, mx = 0, resId = 0, resMx = 0;
        for (int i = 0; i < t.size(); ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resMx < p[i]) {
                resMx = p[i];
                resId = i;
            }
        }
        return s.substr((resId - resMx) / 2, resMx - 1);
    }
};

int main(int argc, const char * argv[]) {
    Solution S;
    string data = "ababd";
    string result = S.longestPalindrome(data);
    cout << result << endl;
    return 0;
}
