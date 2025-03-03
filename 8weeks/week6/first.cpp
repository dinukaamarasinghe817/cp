#include <bits/stdc++.h>

using namespace std;

bool isBijective(const unordered_map<char, string>& mapping) {
    unordered_map<string, char> reverse_mapping;
    for (const auto& pair : mapping) {
        const string& word = pair.second;
        if (reverse_mapping.find(word) != reverse_mapping.end()) {
            return false;
        }
        reverse_mapping[word] = pair.first;
    }
    return true;
}

bool solve(const string& p, const string& s) {
    unordered_map<char, string> mapping;
    istringstream iss(s);
    string word;
    for (char c : p) {
        if (!(iss >> word)) {
            return false;
        }
        if (mapping.find(c) != mapping.end() && mapping[c] != word) {
            return false;
        }
        mapping[c] = word;
    }
    if (iss >> word) {
        return false;
    }
    return isBijective(mapping);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        string p, s;
        getline(cin, p);
        getline(cin, s);
        bool result = solve(p, s);
        cout << boolalpha << result << endl;
    }

    return 0;
}
