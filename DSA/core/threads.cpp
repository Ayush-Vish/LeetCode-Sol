#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

#define int long long int
#define pb push_back
#define pll pair<int, int>
const int modll = 1e17;
const int mod = 1e9 + 7;
const int INF = 1e18;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } }
template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
int fastPow(int a, int b) { int res = 1; while (b) { if (b & 1) { res = (res * a) % mod; } a = (a * a) % mod; b >>= 1; } return res; }

void calculateSum1(int start, int end, int &sum1) {
    sum1 = 0;
    for (int i = start; i < end; i++) {
        sum1 += i;
    }
}

void calculateSum2(int start, int end, int &sum2) {
    sum2 = 0;
    for (int i = start; i < end; i++) {
        sum2 += i;
    }
}

void solve() {
    int n;
    cin >> n;
    int sum1 = 0;
    int sum2 = 0;

    // Measure time without threads
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        if (i > 50) {
            sum1 += i;
        } else {
            sum2 += i;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time without threads: " << duration << " microseconds" << endl;
      cout << sum1 << " " << sum2 << endl;
    // Reset sums
    sum1 = 0;
    sum2 = 0;

    // Measure time with threads
    start = chrono::high_resolution_clock::now();
    thread t1(calculateSum1, 51, n, ref(sum1));
    thread t2(calculateSum2, 0, min(n, 51LL), ref(sum2));
    t1.join();
    t2.join();
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time with threads: " << duration << " microseconds" << endl;

    cout << sum1 << "=?  " << sum2 << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    solve();
    return 0;
}