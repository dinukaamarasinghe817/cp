// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-05/challenges/hogwarts-3
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while(t--){
        string spell;
        cin >> spell;
        getchar();
        int n = spell.length();

        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        map<string,char> strmap;
        map<char,string> charmap;
        int index = 0;
        bool flag = true;
        while(ss >> word){
            if(index == n){
                flag = false;
                break;
            }else if(
                (strmap.find(word) == strmap.end() && charmap.find(spell[index]) == charmap.end())
                || (strmap.find(word) != strmap.end() && charmap.find(spell[index]) != charmap.end() && strmap[word] == spell[index] && charmap[spell[index]] == word)
                ){
                strmap[word] = spell[index];
                charmap[spell[index]] = word;
            }else{
                flag = false;
                index++;
                break;
            }
            index++;
        }
        if(!flag || index!=n){
            cout << "false" << endl;
        }else{
            cout << "true" << endl;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();

    return 0;
}
