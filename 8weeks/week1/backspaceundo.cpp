// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-01/challenges/backspace-and-undo
#include<bits/stdc++.h>

using namespace std;

bool isKey(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
        return true;
    }
    return false;
}

void solve(){
    string seq;
    int t;
    cin >> t;
    while(t--){
        stack<char> plus; stack<char> minus; stack<char> ans; stack<char> lastOP;
        cin >> seq;
        for(int i=0; i<seq.length(); i++){
            char c = seq[i];
            if(isKey(c)){
                plus.push(c);
                lastOP.push(c);
            }else if(c == '<' && !plus.empty()){
                minus.push(plus.top());
                plus.pop();
                lastOP.push(c);
            }else if(c == '^' && !lastOP.empty() && lastOP.top() == '<' && !minus.empty()){
                plus.push(minus.top());
                minus.pop();
                lastOP.pop();
            }else if(c == '^' && !lastOP.empty() && isKey(lastOP.top())){
                plus.pop();
                lastOP.pop();
            }
        }

        while(!plus.empty()){
            ans.push(plus.top());
            plus.pop();
        }

        while(!ans.empty()){
            cout << ans.top();
            ans.pop();
        }
        cout << endl;
    }
    
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    solve();
}