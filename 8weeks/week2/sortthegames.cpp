// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-02/challenges/stellar-star-banner
#include <bits/stdc++.h>
using namespace std;

bool compareGames(const pair<string, vector<int>>& game1, const pair<string, vector<int>>& game2) {
    if (game1.second[0] != game2.second[0]) {
        return game1.second[0] > game2.second[0];
    }

    if (game1.second[1] != game2.second[1]) {
        return game1.second[1] > game2.second[1];
    }

    if (game1.second[2] != game2.second[2]) {
        return game1.second[2] > game2.second[2];
    }

    return game1.first < game2.first;
}

void solve() {
    vector<pair<string,vector<int>>> games;
    int t,score1,score2,score3;
    set<string> gamenames;
    cin >> t;
    int n = t;
    while(t--){
        vector<int> scores;
        string name;
        cin.ignore();
        getline(cin, name);
        if(gamenames.count(name) > 0){
            cin >> score1;
            cin >> score2;
            cin >> score3;
            continue;
        }
        gamenames.insert(name);
        cin >> score1; scores.push_back(score1);
        cin >> score2; scores.push_back(score2);
        cin >> score3; scores.push_back(score3);
        pair<string,vector<int>> gamescores(name,scores);
        games.push_back(gamescores);

    }
    n= gamenames.size();

    sort(games.begin(), games.end(), compareGames);
    int lastrank = 0;
    for (int i=0; i<n; i++) {
        if(i != 0  && (games[i].second[0] == games[i-1].second[0]) && (games[i].second[1] == games[i-1].second[1]) && (games[i].second[2] == games[i-1].second[2])){
        }else{
            lastrank = i+1;
        }
        cout << "#" << lastrank << " " << games[i].first << endl;
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


