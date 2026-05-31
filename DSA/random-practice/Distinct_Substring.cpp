#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        if(K > N) {
            cout << "NO" << endl;
            continue;
        }
        int min_length = K*(K+1)/2;
        if(min_length > N) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}