#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;

        stack<char> stk;
        bool isValid = true;

        for(char c : s){
            if(c == '('){
                stk.push(c);
            }
            else if(c == ')'){
                if(stk.empty()){
                    isValid = false;
                    break;
                }
                stk.pop();
            }
        }

        if(!stk.empty()){
            isValid = false;
        }

        if(isValid){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}