#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    int timeline[101] = {0};
    int arrival_time;
    int departure_time;
    int fee = 0;

    cin >> a >> b >> c;

    for(int i = 0; i < 3; i++){
        cin >> arrival_time >> departure_time;
        for(int t = arrival_time; t < departure_time; t++){
            timeline[t]++;
        }
    }
    
    // 트럭수에 맞는 요금제 계산
    for(int i = 1; i <= 100; i++){
        if(timeline[i] == 1)
            fee += a;
        else if(timeline[i] == 2)
            fee += 2 * b;
        else if(timeline[i] == 3)
            fee += 3 * c;
    }

    cout << fee << '\n';

    return 0;
}