// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-04/challenges/mario-and-the-mysterious-bridge
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minJumpsToReachEnd(int N, int R, int B, int C, int J, vector<pair<int, int>>& redBlocks, vector<pair<int, int>>& blueBlocks, vector<int>& brokenBlocks) {
    vector<int> dp(N + 1, 1e9);

    dp[1] = 0;

    for (int k = 2; k <= N; k++) {
        for (int i = 2; i <= N; i++) {
            if(find(brokenBlocks.begin(), brokenBlocks.end(), i) != brokenBlocks.end()){
                continue;
            }
            for (int j = max(1, i - J); j <= i - 1; j++) {
                if (find(brokenBlocks.begin(), brokenBlocks.end(), j) == brokenBlocks.end()) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }

            // Check for red block jumps
            for (int j = 0; j < R; j++) {
                if (i == redBlocks[j].first+redBlocks[j].second && find(brokenBlocks.begin(), brokenBlocks.end(), redBlocks[j].first) == brokenBlocks.end()) {
                    dp[i] = min(dp[i], dp[redBlocks[j].first]);
                }
            }

            // Check for blue block jumps
            for (int j = 0; j < B; j++) {
                if (i == blueBlocks[j].first-redBlocks[j].second && find(brokenBlocks.begin(), brokenBlocks.end(), blueBlocks[j].first) == brokenBlocks.end()) {
                    dp[i] = min(dp[i], dp[blueBlocks[j].first]);
                }
            }
        }
    }

    return dp[N];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int N, R, B, C, J;
    cin >> N >> R >> B >> C >> J;

    vector<pair<int, int>> redBlocks(R);
    for (int i = 0; i < R; i++) {
        cin >> redBlocks[i].first >> redBlocks[i].second;
    }

    vector<pair<int, int>> blueBlocks(B);
    for (int i = 0; i < B; i++) {
        cin >> blueBlocks[i].first >> blueBlocks[i].second;
    }

    vector<int> brokenBlocks(C);
    for (int i = 0; i < C; i++) {
        cin >> brokenBlocks[i];
    }

    
    cout << minJumpsToReachEnd(N, R, B, C, J, redBlocks, blueBlocks, brokenBlocks) << endl;

    return 0;
}
