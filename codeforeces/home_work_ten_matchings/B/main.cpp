#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

inline int nxt() {
    int n;
    scanf("%d", &n);
    return n;
}

bool vl[N], vr[N];

int main() {
    int n = nxt();
    int m = nxt();
    
    vector<pair<int, int>> r;
    for (int i = 0; i < n; i++) {
        for (int j = nxt(); j != 0; j = nxt()) {
            if (!vl[i] && !vr[j - 1]) {
                r.push_back({i, j - 1});
                vl[i] = true;
                vr[j - 1] = true;
            }
        }
    }
    
    printf("%d\n", int(r.size()));
    for (auto& p : r) printf("%d %d\n", p.first + 1, p.second + 1);
}
