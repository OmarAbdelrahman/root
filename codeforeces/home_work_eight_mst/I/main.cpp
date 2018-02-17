#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;

int main() {
    int n;
    scanf("%d", &n);
    
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i]);
    
    vector<vector<bool>> zero(n, vector<bool>(n, false));
    
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1;
        b -= 1;
        zero[a][b] = zero[b][a] = true;
    }
    
    vector<int> d(n, INF);
    vector<bool> visited(n, false);
    vector<int> p(n);
    
    d[0] = 0;
    for (int t = 0; t < n; t++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || d[u] > d[i]))
                u = i;
        
        visited[u] = true;
        if (d[u] != 0)
            printf("%d %d\n", p[u] + 1, u + 1);
        
        for (int v = 0; v < n; v++)
            if (!visited[v]) {
                int w = zero[u][v] ? 0 : (x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]);
                if (d[v] > w) {
                    d[v] = w;
                    p[v] = u;
                }
            }
    }
}
