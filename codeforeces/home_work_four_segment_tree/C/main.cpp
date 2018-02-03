#include <bits/stdc++.h>
using namespace std;

struct segment_tree
{
    segment_tree(const vector<int>& _a): unvalid(_a)
    {
        t = vector<int>(4 * unvalid.size());
        build(0, 0, unvalid.size() - 1);
    }

    void update(int pos, int x)
    {
        update(0, 0, unvalid.size() - 1, pos, x);
    }

    int query(int l, int r)
    {
        return query(0, 0, unvalid.size() - 1, l, r);
    }

private:
    int left(int i) const
    {
        return 2 * i + 1;
    }

    int right(int i) const
    {
        return 2 * i + 2;
    }

    void collect(int i)
    {
        t[i] = t[left(i)] + t[right(i)];
    }

    void build(int i, int L, int R)
    {
        if (L == R) {
            t[i] = unvalid[L];
        } else {
            int M = (L + R) / 2;
            build(left(i), L, M);
            build(right(i), M + 1, R);
            collect(i);
        }
    }

    void update(int i, int L, int R, int pos, int x)
    {
        if (L == R) {
            t[i] = unvalid[L] = x;
        } else {
            int M = (L + R) / 2;
            if (pos <= M) {
                update(left(i), L, M, pos, x);
            } else {
                update(right(i), M + 1, R, pos, x);
            }
            collect(i);
        }
    }

    int query(int i, int L, int R, int l, int r)
    {
        if (L == l && R == r) {
            return t[i];
        } else {
            int M = (L + R) / 2;
            int result = 0;
            if (l <= M)
                result += query(left(i), L, M, l, min(M, r));
            if (r > M)
                result += query(right(i), M + 1, R, max(l, M + 1), r);
            return result;
        }
    }

    vector<int> t;
    vector<int> unvalid;
};

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[a[i] - 1] = i;
    }

    segment_tree tree(vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", b[i] - tree.query(0, b[i]) + 1);
        tree.update(b[i], 1);
    }
    puts("");
}
