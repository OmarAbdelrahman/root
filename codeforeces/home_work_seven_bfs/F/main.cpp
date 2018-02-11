#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
const int INF = numeric_limits<int>::max() / 2;

char grid[N][N];

struct state {
    int x, y;
};

bool ok(int x, int y, const vector<vector<int>>& v) {
    return x >= 0 && x < int(v.size()) && y >= 0 && y < int(v[x].size()) && v[x][y] == INF && grid[x][y] == '0';
}

vector<vector<int>> bfs(int sx, int sy, int n, int m) {
    vector<vector<int>> dist(n, vector<int>(m, INF));

    dist[sx][sy] = 0;
    queue<state> q;

    for (q.push({sx, sy}); !q.empty(); q.pop()) {
        state s = q.front();
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0) ^ (dy == 0)) {
                    int nx = s.x + dx;
                    int ny = s.y + dy;
                    if (ok(nx, ny, dist)) {
                        dist[nx][ny] = 1 + dist[s.x][s.y];
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int tx = 0, ty = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                tie(tx, ty) = make_tuple(i, j);
            }
        }
    }

    vector<vector<int>> dist = bfs(tx, ty, n, m);

    int k;
    scanf("%d", &k);

    int result = INF;
    int index = -1;

    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        int v = dist[x - 1][y - 1];
        if (v < result) {
            result = v;
            index = i + 1;
        }
    }

    printf("%d\n", index);
}
