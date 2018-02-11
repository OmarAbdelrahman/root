#include <bits/stdc++.h>
using namespace std;

const int N = 55;

const char OBSTACLE = '*';
const char EMPTY = '.';

struct state {
    int x, y, d, c;

    bool operator < (const state& s) const {
        return c > s.c;
    }
};

int n, m;
char grid[N][N];

bool visited[N][N][4];
int dist[N][N][4];

void move(int x, int y, int d, int px, int py, int pd, int added_cost, priority_queue<state>& q) {
    if (x >= 0 && x < n && y >= 0 && y < m) {
        int nc = dist[px][py][pd] + (grid[x][y] == OBSTACLE ? 11 : 2) + added_cost;
        if (dist[x][y][d] > nc) {
            dist[x][y][d] = nc;
            q.push({x, y, d, nc});
        }
    }
}

int solve(int sx, int sy, int tx, int ty) {
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = numeric_limits<int>::max() / 3;
            }
        }
    }

    priority_queue<state> q;
    for (int i = 0; i < 4; i++) {
        dist[sx][sy][i] = 0;
        q.push({sx, sy, i, 0});
    }

    while (!q.empty()) {
        state cur = q.top();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int d = cur.d;
        int c = cur.c;

        if (x == tx && y == ty) {
            return c;
        }

        if (visited[x][y][d]) continue;
        visited[x][y][d] = true;

        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                move(x + 1, y, i, x, y, d, ((d == 2 || d == 3) ? 1 : (d == 1 ? 2 : 0)), q);
            } else if (i == 1) {
                move(x - 1, y, i, x, y, d, ((d == 2 || d == 3) ? 1 : (d == 0 ? 2 : 0)), q);
            } else if (i == 2) {
                move(x, y - 1, i, x, y, d, ((d == 0 || d == 1) ? 1 : (d == 3 ? 2 : 0)), q);
            } else {
                move(x, y + 1, i, x, y, d, ((d == 0 || d == 1) ? 1 : (d == 2 ? 2 : 0)), q);
            }
        }
    }

    return -1;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d%d", &n, &m);

        int sx = -1, sy = -1;
        int tx = -1, ty = -1;

        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'R') {
                    tie(sx, sy) = make_tuple(i, j);
                } else if (grid[i][j] == 'T') {
                    tie(tx, ty) = make_tuple(i, j);
                }
            }
        }

        printf("%d\n", solve(sx, sy, tx, ty));
    }
}
