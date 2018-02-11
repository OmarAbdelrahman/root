#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

map<long long, bool> visited;
map<long long, int> parent;

struct state {
    long long num;
    int cost;
};

void push(long long x, const state& old, queue<state>& q) {
    if (!visited[x]) {
        parent[x] = old.num;
        visited[x] = true;
        q.push({x, old.cost + 1});
    }
}

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);

    visited[a] = true;
    parent[a] = a;

    bool found = false;
    queue<state> q;

    for (q.push({a, 0}); !q.empty(); q.pop()) {
        state s = q.front();
        if (s.num == b) {
            found = true;
            printf("%d\n", s.cost);
            vector<int> r;
            while (b != a) {
                r.push_back(b);
                b = parent[b];
            }
            printf("%d", a);
            for (int i = r.size() - 1; i >= 0; i--) {
                printf(" %d", r[i]);
            }
            puts("");
            break;
        }

        long long n1 = (s.num + 1) % n;
        long long n2 = ((s.num % n) * (s.num % n) + (1 % n)) % n;
        long long n3 = ((s.num % n) * (s.num % n) * (s.num % n) + (1 % n)) % n;

        push(n1, s, q);
        push(n2, s, q);
        push(n3, s, q);
    }
    
    if (!found) puts("-1");
}
