#include <bits/stdc++.h>

using namespace std;

bool isAcceptable(string s) {
    int vowelCount = 0;
    int consonantCount = 0;
    bool isVowel = false;

    for(int i = 0; i < s.length(); i++){
        if('a' == s[i] || 'e' == s[i] || 'i' == s[i] || 'o' == s[i] || 'u' == s[i]){
            vowelCount++;
            consonantCount = 0;
            isVowel = true;
        }
        else{
            vowelCount = 0;
            consonantCount++;
        }
        if(vowelCount >= 3 || consonantCount >= 3) return false;
    }
    if(!isVowel) return false;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == s[i+1]){
            if(s[i] != 'e' || s[i] != 'o')
                return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while(true){
        cin >> str;
        if (str == "end") break;
        if (isAcceptable(str)) {
            cout << "<" << str << "> is acceptable." << '\n';
        } else {
            cout << "<" << str << "> is not acceptable." << '\n';
        }
    }

    return 0;
}