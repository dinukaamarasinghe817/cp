// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-01/challenges/top-gun
#include<bits/stdc++.h>

using namespace std;

double delta(double u, double v, double D, double R) {
    double result = 4*pow(u,2)*(pow(D,2) - pow(R,2))*(pow(u,2)*pow(R,2) - pow(D,2)*(pow(u,2) - pow(v,2)));
    return result;
}

void solve(){
    int t;
    cin >> t;
    double u,v,d,r;
    while(t--){
        cin >> u >> v >> d >> r;
        if(d <= r || (delta(u,v,d,r) >= 0)){
            cout << "SHOOT" << endl;
        }else{
            cout << "DONT" << endl;
        }
    } 
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    
    solve();
}