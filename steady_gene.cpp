#include<bits/stdc++.h>

using namespace std;

int n;
map <char,int> cnt = {{'A',0},{'C',0},{'G',0},{'T',0}};

bool isBalancedWindow() {
    int target = n/4;
    for(char c : "ACGT") {
        if(cnt[c] > target) {
            return false;
        }
    }
    return true;
}

void solve(){
    string s;
    cin >> n >> s;
    for(int value: s) {
        cnt[value]++;
    }
    if(isBalancedWindow()) {
        cout << 0 << endl;
        return;
    }

    int ans = n,j=0;
    for(int i=0; i<n; i++) {
        while(j<n && !isBalancedWindow()) {
            cnt[s[j++]]--;
        }
        if(isBalancedWindow()) {
            ans = min(ans,j-i);
        }
        cnt[s[i]]++;
        if(!isBalancedWindow() && j==n-1) {
            break;
        }
    }
    cout << ans << endl;
}

int main() {

    // Uncomment these lines if your inputs/outputs are taken from or given to a file
  
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    
    solve();
    
}
