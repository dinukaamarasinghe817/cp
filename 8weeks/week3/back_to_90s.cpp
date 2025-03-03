// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-03/challenges/back-to-the-90s
#include<bits/stdc++.h>
using namespace std;

int maxh(const vector<int>& nums, int startIdx, int endIdx);

void solve(){
    int N,start,end,width,res=0;
    cin >> N;
    
    vector<int> xaxis(100005, 0);
    for (int i = 0; i < N; i++) {
        cin >> start >> width;
        end = start + width -1;

        int maxheight = maxh(xaxis,start,end);
        maxheight+=width;
        for(int i=start; i<=end; i++) {
            xaxis[i] = maxheight;
        }
        res = max(res,maxheight);
    }

    cout << res << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    solve();
}

int maxh(const vector<int>& nums, int startIdx, int endIdx) {
    if (startIdx < 0 || endIdx >= nums.size() || startIdx > endIdx) {
        return -1;
    }

    int h = nums[startIdx];
    for (int i = startIdx + 1; i <= endIdx; i++) {
        if (nums[i] > h) {
            h = nums[i];
        }
    }

    return h;
}