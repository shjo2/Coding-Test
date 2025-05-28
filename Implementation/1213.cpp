#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    cin >> name;

    int alpha_count[26] = {0};
    for (char c : name) {
        alpha_count[c - 'A']++;
    }

    int odd_count = 0;
    char middle = '\0';
    string front = "";

    for (int i = 0; i < 26; i++) {
        if (alpha_count[i] % 2) {
            odd_count++;
            middle = 'A' + i;
            if (odd_count > 1) {
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
        }

        for (int j = 0; j < alpha_count[i] / 2; j++) {
            front += (char)('A' + i);
        }
    }

    string end = front;
    reverse(end.begin(), end.end());
    string result = front;
    if (middle != '\0') {
        result += middle;
    }
    result += end;
    
    cout << result << '\n';
    return 0;
}