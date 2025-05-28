#include <bits/stdc++.h>

using namespace std;

long long power(long long a, long long b, long long c){
    if(b == 0){
        return 1;
    }
    
    long long res = 1;

    long long half = power(a, b/2, c);
    res = (half * half) % c;

    if(b % 2 != 0){
        res = (res * (a % c)) % c;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long A, B, C;
    cin >> A >> B >> C;

    cout << power(A, B, C) << '\n';

    return 0;
}