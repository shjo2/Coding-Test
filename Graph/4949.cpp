#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        string str;
        getline(cin, str);

        stack<char> stk;
        bool isValid = true;

        if(str == "."){
            break;
        }

        for(char c : str){
            if(c == '(' || c == '['){
                stk.push(c);
            }
            else if(c == ')'){
                if(stk.empty() || stk.top() != '('){
                    isValid = false;
                    break;
                }
                stk.pop();
            }

            if(c == ']'){
                if(stk.empty() || stk.top() != '['){
                    isValid =  false;
                    break;
                }
                stk.pop();
            }
        }

        if (!stk.empty()) {
            isValid = false;
        }
        
        if(isValid){
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }
    }

    return 0;
}