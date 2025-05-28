#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int count = 0;
    int num = 665;
    int result_number = 0;
    while(true){
        num++;

        string s = to_string(num);

        if(s.find("666") != string::npos){
            count++;
        }

        if(count == n){
            result_number = num;
            break;
        }
    }

    cout << result_number << '\n';

    return 0;
}