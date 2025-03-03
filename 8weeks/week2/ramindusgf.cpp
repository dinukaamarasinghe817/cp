// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-02/challenges/help-ramindu-unlock-the-door
#include <bits/stdc++.h>
#include <regex>
using namespace std;

string reverseSubstring(const string& input) {
    regex pattern("[aAcCmM8wWeEkKsS\\-]+");
    smatch match;
    if (regex_search(input, match, pattern)) {
        string matchedStr = match.str();
        reverse(matchedStr.begin(), matchedStr.end());
        string remaining = match.suffix();
        return reverseSubstring(remaining) + matchedStr;
    }
    return "";
}

string replaceRegexWithSubstring(string input, string replacementStr) {
    regex pattern("[aAcCmM8wWeEkKsS\\-]+");
    smatch match;

    if (regex_search(input, match, pattern)) {
        string matchedStr = match.str();
        int n = matchedStr.size();
        string substringToReplace = matchedStr.substr(0, n);

        return match.prefix().str() + replacementStr.substr(0,n) + replaceRegexWithSubstring(match.suffix(), replacementStr.substr(n));
        }
    return input;
}

void solve(){
    string str;
    getline(cin, str);
    cout << replaceRegexWithSubstring(str, reverseSubstring(str));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    solve();

    return 0;
}
