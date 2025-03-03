// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-02/challenges/stellar-star-banner
#include <bits/stdc++.h>
using namespace std;


void solve() {
    int t,h;
    cin >> t;
    while(t--){
        cin >> h;
        if(h>21 || h<5){
            cout << "Out of Reach!" << endl;
            continue;
        }else if(h%2==0){
            cout << "Strange!" << endl;
            continue;
        }

        for(int i=0; i<h; i++){
            cout << " ";
            for(int j=1; j<2*h; j++){
                if(i==(h/2) && (j>(2*h-1-h)/2 && j<=((2*h-1-h)/2)+h)){
                    cout << "*";

                }else if(i==(h/2)){
                    cout << " ";
                    
                }else if(j==(h+i) || j==(h-i)){
                    cout << "*";
                }else{
                    cout << " ";
                }
                
            }
            cout << "  ";

            for(int j=1; j<2*h; j++){
                if((i==0 || i==(h-1)) && j%2){
                    cout << "*";
                }else if(i>0 && i<h-1 && j==1){
                    cout << "*";
                }else{
                    cout << " ";
                }
            }
            cout << "  ";

            for(int j=1; j<2*h; j++){
                if(j==1 || j==(2*h)-1){
                    cout << "*";
                }else if(j==(h-(h-(i+1))) || j==(h+(h-(i+1)))){
                    cout << "*";
                }else{
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    solve();

    return 0;
}


