#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> goals;
    for(int i = 0; i < n; i++){
        int team_number;
        string goal_time;
        cin >> team_number >> goal_time;

        int minutes = stoi(goal_time.substr(0, 2));
        int seconds = stoi(goal_time.substr(3, 2));
        int total_seconds = minutes * 60 + seconds;
        goals.push_back({total_seconds, team_number});
    }

    sort(goals.begin(), goals.end());
    
    int score1 = 0, score2 = 0;
    int time1 = 0, time2 = 0;
    int last_time = 0;

    for(int i = 0; i < n; i++){
        int time = goals[i].first;
        int team = goals[i].second;

        if(score1 > score2){
            time1 += time - last_time;
        } else if(score2 > score1){
            time2 += time - last_time;
        }

        if(team == 1){
            score1++;
        } else {
            score2++;
        }

        last_time = time;
    }

    int end_time = 48 * 60;
    if(score1 > score2){
        time1 += end_time - last_time;
    } else if(score2 > score1){
        time2 += end_time - last_time;
    }

    printf("%02d:%02d\n", time1 / 60, time1 % 60);
    printf("%02d:%02d\n", time2 / 60, time2 % 60);

    return 0;
}