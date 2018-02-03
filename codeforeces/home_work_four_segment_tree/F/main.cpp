#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
    segment_tree(const vector<int>& a): empty(a), t(4 * a.size()) {
        build(0, 0, empty.size() - 1);
    }

    void update(int pos, int x) {
        update(0, 0, empty.size() - 1, pos, x);
    }

    int query(int pos) {
        return query(0, 0, empty.size() - 1, pos);
    }

private:
    void collect(int i) {
        t[i] = t[2 * i + 1] + t[2 * i + 2];
    }

    void build(int i, int L, int R) {
        if (L == R) {
            t[i] = empty[L];
        } else {
            int M = (L + R) / 2;
            build(2 * i + 1, L, M);
            build(2 * i + 2, M + 1, R);
            collect(i);
        }
    }

    void update(int i, int L, int R, int pos, int x) {
        if (L == R) {
            t[i] = empty[L] = x;
        } else {
            int M = (L + R) / 2;
            if (pos <= M) {
                update(2 * i + 1, L, M, pos, x);
            } else {
                update(2 * i + 2, M + 1, R, pos, x);
            }
            collect(i);
        }
    }

    int query(int i, int L, int R, int pos) {
        if (L == R) {
            return L;
        } else {
            int M = (L + R) / 2;
            if (pos < t[2 * i + 1])
                return query(2 * i + 1, L, M, pos);
            else
                return query(2 * i + 2, M + 1, R, pos - t[2 * i + 1]);
        }
    }

    vector<int> empty;
    vector<int> t;
};

int main() {
    int n;
    scanf("%d", &n);

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    vector<int> pos(n);
    segment_tree tree(vector<int>(n, 1));
    for (int i = 0; i < n; i++) {
        int xi = tree.query(t[i]);
        tree.update(xi, 0);
        pos[xi] = i;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", pos[i] + 1);
    }
    puts("");
}
