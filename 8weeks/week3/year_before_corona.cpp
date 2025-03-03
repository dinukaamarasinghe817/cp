// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-03/challenges/disjoint-year
#include <stdio.h>

bool isAns(int year) {
    int digits[10] = {0};

    while (year > 0) {
        int digit = year % 10;
        if (digits[digit] > 0) {
            return 0;
        }
        digits[digit] = 1;
        year /= 10;
    }
    return 1;
}

void solve(){
    int year;
    scanf("%d", &year);

    while (1) {
        year++;
        if (isAns(year)) {
            printf("%d\n", year);
            break;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    solve();
    return 0;
}
