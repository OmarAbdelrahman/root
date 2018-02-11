#include <bits/stdc++.h>
using namespace std;

const int N = 50;

struct state
{
    int x, y, c;
};

char col[N];
bool visited[N][N];
pair<int, int> parent[N][N];

int n, m;
int sx, sy;
int tx, ty;

void bfs() {
    visited[sx][sy] = true;
    parent[sx][sy] = make_pair(sx, sy);

    queue<state> q;
    for (q.push({sx, sy, 0}); !q.empty(); q.pop()) {
        state s = q.front();

        if (s.x == tx && s.y == ty) {
            printf("%d\n", s.c);
            vector<string> r;
            while (tx != sx || ty != sy) {
                auto prev = parent[tx][ty];
                int px = prev.first;
                int py = prev.second;

                if (tx - 1 == px) {
                    if (ty - 1 == py) r.push_back("SE");
                    if (ty == py) r.push_back("S");
                    if (ty + 1 == py) r.push_back("SW");
                } else if (tx == px) {
                    if (ty - 1 == py) r.push_back("E");
                    if (ty + 1 == py) r.push_back("W");
                } else if (tx + 1 == px) {
                    if (ty - 1 == py) r.push_back("NE");
                    if (ty == py) r.push_back("N");
                    if (ty + 1 == py) r.push_back("NW");
                }
                tx = px;
                ty = py;
            }
            for (int i = r.size() - 1; i >= 0; i--) printf("%s\n", r[i].c_str());
            return;
        }

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = s.x + dx;
                int ny = s.y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    parent[nx][ny] = {s.x, s.y};
                    q.push({nx, ny, s.c + 1});
                }
            }
        }

    }
    puts("-1");
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", col);
        for (int j = 0; j < m; j++) {
            if (col[j] == '#')
                visited[i][j] = true;
            if (col[j] == 'S')
                sx = i, sy = j;
            if (col[j] == 'F')
                tx = i, ty = j;

            parent[i][j] = {-1, -1};
        }
    }
    bfs();
}
