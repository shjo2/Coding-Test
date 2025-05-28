#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        
        long long count = 0;
        for(int j = 5; j <= N; j *= 5){
            count += N / j;
        }

        cout << count << '\n';
    }

    return 0;
}