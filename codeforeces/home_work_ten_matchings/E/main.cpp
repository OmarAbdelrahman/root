#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int M = 26 * 26;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

vector<int> g[N];
int R[M];
bool visited[N];

bool enlarge(int u) {
    if (visited[u]) return false;
    visited[u] = true;
    for (int v : g[u]) {
        if (R[v] == -1 || enlarge(R[v])) {
            R[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    for (int n = nxt(); n != 0; n = nxt()) {
        memset(R, -1, sizeof(R));
        for (int i = 0; i < N; i++) {
            g[i].clear();
        }
        
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            for (int j = 1; j < (int) name.size(); j++) {
                char a = tolower(name[0]);
                char b = tolower(name[j]);
                int id = (a - 'a') * 26 + (b - 'a');
                g[i].push_back(id);
            }
        }
        
        int r = 0;
        for (int i = 0; i < n; i++) {
            memset(visited, false, sizeof(visited));
            r += (int) enlarge(i);
        }
    
        printf("%d\n", r);
    }
}
