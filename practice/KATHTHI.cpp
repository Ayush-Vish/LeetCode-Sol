#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e15;
char grid[1003][1003];
int dist[1003][1003];

void solve() {
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            dist[i][j] = INF;

    deque<pair<int, int>> dq;
    dq.emplace_front(0, 0);
    dist[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
                int cost = (grid[x][y] != grid[nx][ny]);
                if (dist[nx][ny] > dist[x][y] + cost) {
                    dist[nx][ny] = dist[x][y] + cost;
                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
    }

    cout << dist[r - 1][c - 1] << '\n';
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
