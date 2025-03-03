// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-04/challenges/magical--eraser
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

string simplify(string S)
{
    string new_str;
    int N = S.length();

    int i = 0;

    while (i < N) {

        new_str += S[i];
        int j = i;
        while (i < N && S[i] == S[j])
            ++i;
    }
    return new_str;
}

int minErases(int l, int r, vector<vector<int>>& dp, string s) {

    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (dp[l][r] != -1)
        return dp[l][r];

    int res = 1 + minErases(l + 1, r, dp, s);

    for (int i = l + 1; i <= r; ++i) 
        if (s[l] == s[i])
            res = min(res, minErases(l + 1, i - 1, dp, s) + minErases(i, r, dp, s));

    return dp[l][r] = res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = simplify(s);
    n = s.length();
    vector<vector<int>> dp(N,vector<int>(N,-1));
    cout << minErases(0, n - 1, dp, s);

    return 0;
}