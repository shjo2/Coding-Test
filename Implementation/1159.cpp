#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    char playerNames[32][32];
    int firstLetter[26] = {0};
    bool isExist = false;

    for(int i = 0; i < n; i++){
        cin >> playerNames[i];

        char firstCharacter = playerNames[i][0];
        if(firstCharacter >= 'a' && firstCharacter <= 'z')
            firstLetter[firstCharacter - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(firstLetter[i] >= 5){
            cout << (char)('a' + i);
            isExist = true;
        }
    }
    
    if(!isExist)
        cout << "PREDAJA" << '\n';
    return 0;
}