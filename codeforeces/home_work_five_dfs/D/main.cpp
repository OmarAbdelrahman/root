#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int W = 0;
const int G = 1;
const int B = 2;

char row[N];
int components[N * N];
int color[N][N];
vector<vector<int>> g;
int n, m;

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 1;
}

int dfs(int x, int y) {
    color[x][y] = G;
    int result = 1;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if ((dx == 0) ^ (dy == 0)) {
                int nx = x + dx;
                int ny = y + dy;
                if (ok(nx, ny) && color[nx][ny] == W)
                    result += dfs(nx, ny);
            }
        }
    }
    color[x][y] = B;
    return result;
}

int main() {
    scanf("%d%d", &n, &m);

    g.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%s", row);
        g[i].resize(m);
        for (int j = 0; j < m; j++) {
            g[i][j] = (int) row[j] == '.';
        }
    }

    int ncomponents = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (color[i][j] == W && g[i][j] == 1) {
                components[ncomponents] = dfs(i, j);
                ncomponents += 1;
            }
        }
    }
    sort(components, components + ncomponents);

    printf("%d\n", ncomponents);
    for (int i = 0; i < ncomponents; i++) {
        if (i > 0) printf(" ");
        printf("%d", components[i]);
    }
    puts("");
}
