#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        if (s.size() != n) {
            cout << "NO" << endl;
            continue;
        }

        unordered_map<char, int> charToInt;
        unordered_map<int, char> intToChar;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (charToInt.find(s[i]) != charToInt.end()) {
                if (charToInt[s[i]] != a[i]) {
                    ok = false;
                    break;
                }
            } else {
                charToInt[s[i]] = a[i];
            }

            if (intToChar.find(a[i]) != intToChar.end()) {
                if (intToChar[a[i]] != s[i]) {
                    ok = false;
                    break;
                }
            } else {
                intToChar[a[i]] = s[i];
            }
        }

        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}