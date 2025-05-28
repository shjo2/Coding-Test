#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n){

        int remainder = 1;
        int digit_count = 1 % n;

        while(true){
            if(remainder % n == 0){
                cout << digit_count << '\n';
                break;
            }

            remainder = (remainder * 10 + 1) % n;
            digit_count++;
        }
    }

    return 0;
}