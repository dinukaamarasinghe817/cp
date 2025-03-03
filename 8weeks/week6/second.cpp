#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100;

vector<long long> calculateFactorials() {
    vector<long long> factorials(MAX_N + 1, 1);
    for (int i = 2; i <= MAX_N; ++i) {
        factorials[i] = factorials[i - 1] * i;
    }
    return factorials;
}

int main() {
    vector<long long> factorials = calculateFactorials();

    cout << "my_list = [";
    for (int i = 1; i <= MAX_N; ++i) {
        cout << factorials[i];
        if (i < MAX_N) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
