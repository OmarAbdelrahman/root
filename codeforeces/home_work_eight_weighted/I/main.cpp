#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 3;

struct state {
    int x;
    int c;
    int ei;
    
    bool operator < (const state& s) const {
        return c > s.c;
    }
};

int gcd(int a, int b) {
    while (b > 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void dijkstra(int s, int t, vector<int> ws, vector<vector<state>> g) {
    const int n = g.size();
    const int m = ws.size();
    
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    priority_queue<state> q;
    
    bool found = false;
    dist[s][0] = 0;
    parent[s][0] = {s, 0};
    
    for (q.push({s, 0, 0}); !q.empty();) {
        state cur = q.top();
        q.pop();
        
        int u = cur.x;
        int i = cur.ei;
        
        if (u == t) {
            found = true;
            int index = 1;
            for (int j = 2; j < m; j++) {
                if (dist[u][j] < dist[u][index]){
                    index = j;
                }
            }
            vector<int> path;
            while (t != s) {
                path.push_back(t);
                pair<int, int> prev = parent[t][index];
                t = prev.first;
                index = prev.second;
            }
            path.push_back(t);
            printf("%d", int(path.size()));
            for (int j = path.size() - 1; j >= 0; j--) {
                printf(" %d", path[j] + 1);
            }
            puts("");
            break;
        }
        
        if (visited[u][i]) continue;
        visited[u][i] = true;
        
        for (const auto& next : g[u]) {
            int v = next.x;
            int j = next.ei;
            int c = next.c;
            if (gcd(ws[i], ws[j]) == 1 && dist[v][j] > dist[u][i] + c) {
                dist[v][j] = dist[u][i] + c;
                parent[v][j] = {u, i};
                q.push({v, dist[v][j], j});
            }
        }
    }
    
    if (!found) puts("-1");
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        int n, m, s, t;
        scanf("%d%d%d%d", &n, &m, &s, &t);

        s -= 1;
        t -= 1;
        
        vector<int> ws(m + 1, 1);
        vector<vector<state>> g(n);
        
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a -= 1;
            b -= 1;
            ws[i + 1] = c;
            g[a].push_back({b, c, i + 1});
            g[b].push_back({a, c, i + 1});
        }
        
        dijkstra(s, t, ws, g);
    }
}
