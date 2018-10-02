//
//  main.cpp
//  10. Regular Expression Matching
//
//  Created by 于博尧 on 2018/9/15.
//  Copyright © 2018年 于博尧. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution{
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        vector<vector<bool>> f(p.size() + 1, vector<bool>(s.size() + 1, false));
        f[0][0] = true;
        if (!s.empty()) f[1][1] = p[0] == '.' || p[0] == s[0];
        for (int u = 2; u <= p.size(); ++u) {
            f[u][0] = p[u - 1] == '*' && f[u - 2][0];
            for (int i = 1; i <= s.size(); ++i)
                f[u][i] =
                (p[u - 1] == '.' || ((p[u - 1] == s[i - 1]) && f[u - 1][i - 1])) ||
                (p[u - 1] == '*' && (f[u - 2][i] ||
                (f[u][i - 1] && (p[u - 2] == '.' || p[u - 2] == s[i - 1]))));
        }
        return f[p.size()][s.size()];
    }

};

int main(int argc, const char * argv[]) {
    Solution S;
    string s = "aaa";
    string p = "a*a";
    bool result = S.isMatch(s, p);
    cout << (result ? "true" : "false") << endl;
    return 0;
}


