// Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-03/challenges/the-pharaohs-fortune-can-you-help-the-king-kufu
#include<bits/stdc++.h>

using namespace std;

char findLowestCharacter(char c1, char c2, char c3, char c4);
char findLowestCharacter(char c1, char c2, char c3);
char findLowestCharacter(char c1, char c2);

void solve(){
    string str1,str2,d;
    cin >> str1 >> str2 >> d;

    char map[26];
    for(int i = 0; i < 26; i++){
        map[i] = '@';
    }

    for(int i=0;i<str1.length();i++){
        char f = str1[i];
        char s = str2[i];

        if(map[f-'a']!='@'){
            if(map[s-'a']!='@'){
                for(int i=0; i<26; i++){
                    if((i!= (f-'a') && i!= (s-'a')) && (map[i] == map[f-'a'] || map[i] == map[s-'a'])){
                        map[i] = findLowestCharacter(f,s,map[f-'a'],map[s-'a']);
                    }
                }
                map[f-'a']=findLowestCharacter(f,s,map[f-'a'],map[s-'a']);
                map[s-'a']=findLowestCharacter(f,s,map[f-'a'],map[s-'a']);
            }else{
                for(int i=0; i<26; i++){
                    if((i!= (f-'a') && i!= (s-'a')) && (map[i] == map[f-'a'])){
                        map[i] = findLowestCharacter(f,s,map[f-'a']);
                    }
                }
                map[f-'a']=findLowestCharacter(f,s,map[f-'a']);
                map[s-'a']=findLowestCharacter(f,s,map[f-'a']);
            }
        }else{
            if(map[s-'a']!='@'){
                for(int i=0; i<26; i++){
                    if((i!= (f-'a') && i!= (s-'a')) && (map[i] == map[s-'a'])){
                        map[i]=findLowestCharacter(f,s,map[s-'a']);
                    }
                }
                map[f-'a']=findLowestCharacter(f,s,map[s-'a']);
                map[s-'a']=findLowestCharacter(f,s,map[s-'a']);
            }else{
                map[f-'a']=findLowestCharacter(f,s);
                map[s-'a']=findLowestCharacter(f,s);
            }
        }
    }
    for(int i = 0; i <d.length(); i++){
        if(map[d[i]-'a']!='@'){
            cout << map[d[i]-'a'];
        }else{
            cout << d[i];
        }
    }

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    solve();
}


char findLowestCharacter(char c1, char c2, char c3, char c4) {
    return std::min(c1, min(c2, min(c3, c4)));
}

char findLowestCharacter(char c1, char c2, char c3) {
    return min(c1, min(c2, c3));
}

char findLowestCharacter(char c1, char c2) {
    return min(c1, c2);
}