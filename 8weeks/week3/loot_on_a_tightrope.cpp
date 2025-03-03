// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-03/challenges/loot-on-a-tightrope
#include<bits/stdc++.h>

using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n,ans=0,p;
        cin >> n;
        vector<int> v;
        for(int i=0; i<n; i++){
            cin >> p;
            v.push_back(p);
        }
        sort(v.begin(), v.end(), greater<int>());

        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(v[i]==v[j]){
                    ans = max(ans,v[i]+v[j]);
                }
            }
        }

        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                for(int k=j+1; k<n-1; k++){
                        if(v[i] == v[k]+v[j]){
                            ans = max(ans,v[i]+v[j]+v[k]);
                        }
                    }
                }
            }

        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                for(int k=j+1; k<n-1; k++){
                    for(int l=k+1; l<n; l++){
                            if(v[i]+v[l] == v[k]+v[j]){
                                ans = max(ans,v[i]+v[j]+v[k]+v[l]);
                            }
                        }
                    }
                }
            }

        cout << ans << endl;


    }

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    solve();
}