#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    getline(cin, S);

    for(int i = 0; i < S.length(); i++){
        if(isalpha(S[i])){
            char c;
            if(isupper(S[i]))
                c = 'A';
            else
                c = 'a';

            S[i] = c + (S[i] - c + 13) % 26;
        }
    }

    for(int i = 0; i < S.length(); i++){
        cout << S[i];
    }
    cout << endl;

    return 0;
}