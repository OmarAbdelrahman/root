#include <bits/stdc++.h>
using namespace std;

const int N = 301;
const int R = 101;
const int INF = numeric_limits<int>::max() / 4;

bool visited[N][R][2];
int dist[N][R][2];
state parent[N][R][2];

struct state {
    int i;
    int t;
    int b;
    int c;
    
    bool operator < (const state& s) const {
        return  c > s.c;
    }
};

struct vertex {
    int i;
    int color;
    int time_to_change;
    int b_time;
    int p_time;
    
    vector<pair<vertex*, int>> adj;
    
    vertex(int _i, int _c, int _ch, int _b, int _p):
        i(_i), color(_c), time_to_change(_ch),
        b_time(_b), p_time(_p) { }
};

void dijkstra(int s, int t, const vector<vertex*>& graph) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < 2; k++) {
                dist[i][j][k] = INF;
                parent[i][j][k] = {-1, -1, -1, -1};
            }
        }
    }
    memset(visited, false, sizeof(visited));
    
    priority_queue<state> q;
    for (int i = 0; i < 2; i++) {
        dist[s][0][i] = 0;
        q.push({s, 0, i, 0});
    }
    
    for (int T = 0; !q.empty(); T++) {
        state cur = q.top();
        q.pop();
        
        int u = cur.i;
        int t = cur.t;
        int b = cur.b;
        
        if (u == t) {
            // found solution
            break;
        }
        
        if (visited[u][t][b]) continue;
        visited[u][t][b] = true;
        
        for (const auto& next : graph[u]->adj) {
            int v = next.first->i;
            int
        }
    }
}

int main() {
    int s, t;
    scanf("%d%d", &s, &t);
    
    s -= 1;
    t -= 1;
    
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<vertex*> graph(n);
    for (int i = 0; i < n; i++) {
        char color[2];
        int t, rb, rp;
        scanf("%s%d%d%d", color, &t, &rb, &rp);
        graph[i] = new vertex(i, color[0] == 'P', t, rb, rp);
    }
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a -= 1;
        b -= 1;
        g[a]->adj.push_back({g[b], c});
        g[b]->adj.push_back({g[a], c});
    }
    
    dijkstra(s, t);
}
