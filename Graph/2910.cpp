#include <bits/stdc++.h>

using namespace std;

struct Info{
    int number;
    int freq;
    int first_index;
};

bool cmp(Info a, Info b){
    if(a.freq != b.freq) return a.freq > b.freq;
    return a.first_index < b.first_index;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C;
    cin >> N >> C;

    map<int, int> freq;
    map<int, int> firstIdx;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        freq[num]++;
        if(firstIdx.find(num) == firstIdx.end()){
            firstIdx[num] = i;
        }
    }

    vector<Info> info;
    for(auto& p : freq){
        info.push_back({p.first, p.second, firstIdx[p.first]});
    }

    sort(info.begin(), info.end(), cmp);

    for(auto& i : info){
        for(int j = 0; j < i.freq; j++){
            cout << i.number << " ";
        }
    }
    cout << '\n';

    return 0;
}