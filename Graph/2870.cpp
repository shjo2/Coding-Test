#include <bits/stdc++.h>

using namespace std;

bool compare(const string& a, const string& b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> v;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        string num;
        for (char c : s) {
            if (isdigit(c)) {
                num += c;
            } else {
                if (!num.empty()) {
                    while(num.length() > 1 && num[0] == '0')
                        num.erase(0, 1);
                    v.push_back(num);
                }
                num = "";
            }
        }
        if (!num.empty()) {
            while(num.length() > 1 && num[0] == '0')
                num.erase(0, 1);
            v.push_back(num);
        }
    }

    sort(v.begin(), v.end(), compare);

    for(const auto& n : v){
        cout << n << '\n';
    }

    return 0;
}