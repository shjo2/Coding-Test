#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, j;
    cin >> n >> m >> j;
    
    int left = 1;
    int distance = 0;
    for(int i = 0; i < j; i++){
        int apple;
        cin >> apple;

        if(apple < left){
            distance += abs(left - apple);
            left = apple;
        }
        else if(apple > left + m - 1){
            distance += abs(apple - (left + m - 1));
            left = apple - m + 1;
        }
    }
    
    cout << distance << '\n';

    return 0;
}