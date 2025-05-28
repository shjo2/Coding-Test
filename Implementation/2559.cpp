#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int k;
    cin >> n >> k;

    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += vec[i];
    }

    int max_sum = sum;
    for(int i = k; i < n; i++){
        sum += vec[i] - vec[i - k];

        max_sum = max(max_sum, sum);
    }

    cout << max_sum << '\n';

    return 0;
}