#include <bits/stdc++.h>
using namespace std;

const int N = 129;

vector<vector<int>> ds = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}, {1, 0, 0}, {0, 1, 1}, {0, 1, 0}, {0, 0, 1}, {0, 0, 0}};

int n;
int f[N][N][N];

void update(int x, int y, int z, int by)
{
    for (; x < n; x |= (x + 1)) {
        for (int i = y; i < n; i |= (i + 1)) {
            for (int j = z; j < n; j |= (j + 1)) {
                f[x][i][j] += by;
            }
        }
    }
}

int query(int x, int y, int z)
{
    int result = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
        for (int i = y; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = z; j >= 0; j = (j & (j + 1)) - 1) {
                result += f[x][i][j];
            }
        }
    }
    return result;
}

int query(int x1, int y1, int z1, int x2, int y2, int z2)
{
    vector<vector<int>> ta = {{x2, y2, z2}, {x1, y1, z1}};

    int result = 0;
    for (int i = 0; i < 8; i++) {
        int x = ta[ds[i][0]][0] - ds[i][0];
        int y = ta[ds[i][1]][1] - ds[i][1];
        int z = ta[ds[i][2]][2] - ds[i][2];
        int p = ds[i][0] + ds[i][1] + ds[i][2];
        if (p % 2 == 0)
            result += query(x, y, z);
        else
            result -= query(x, y, z);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int c; cin >> c && c != 3; ) {
        if (c == 1) {
            int x, y, z, d;
            cin >> x >> y >> z >> d;
            update(x, y, z, d);
        } else {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << query(x1, y1, z1, x2, y2, z2) << '\n';
        }
    }
}
