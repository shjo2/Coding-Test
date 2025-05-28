#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string words;
    string reverseWords;

    cin >> words;

    for(int i = words.length() - 1; i >= 0; i--){
        reverseWords += words[i];
    }

    if(words == reverseWords)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;
}