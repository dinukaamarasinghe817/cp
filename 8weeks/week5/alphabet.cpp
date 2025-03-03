// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-05/challenges/mysterious-alphabet
#include <bits/stdc++.h>

using namespace std;

bool isSentenceCorrect(const vector<string>& alphabet, const string& sentence) {
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        string pattern = "(";
        for (const string& letter : alphabet) {
            pattern += letter + "|";
        }
        pattern.pop_back();
        pattern += ")+";

        regex regexPattern(pattern);

        if (!regex_match(word, regexPattern)) {
            return false;
        }
    }
    return true;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    int n, t;
    cin >> n >> t;

    vector<string> alphabet;
    while (n--) {
        string letter;
        cin >> letter;
        alphabet.push_back(letter);
    }

    cin.ignore();

    while (t--) {
        string sentence;
        getline(cin, sentence);

        if (isSentenceCorrect(alphabet, sentence)) {
            cout << "TRUE" << endl;
        } else {
            cout << "FALSE" << endl;
        }
    }

    return 0;
}
