#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;
    
    int alphabet[26] = {0};

    for(char ch : str){
        if(ch >= 'a' && ch <= 'z'){
            int index = ch - 'a';
            alphabet[index]++;
        }
    }

    for(int i = 0; i < 26; i++){
        cout << alphabet[i] << " ";
    }
    cout << endl;


    return 0;
}