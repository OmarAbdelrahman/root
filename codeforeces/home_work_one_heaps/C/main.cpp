#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

struct heap_t
{
    void heapify(int pos = 0)
    {
        while (pos < size()) {
            int child = L(pos);
            if (child >= size()) break;
            if (R(pos) < size() && h[R(pos)] < h[child]) {
                child++;
            }
            if (h[child] >= h[pos]) break;
            swap(h[child], h[pos]);
            pos = child;
        }
    }

    void add(int x)
    {
        h.push_back(x);
        int pos = size() - 1;
        while (pos != 0 && h[prev(pos)] > h[pos]) {
            swap(h[prev(pos)], h[pos]);
            pos = prev(pos);
        }
    }

    int head() const
    {
        return h[0];
    }

    void pop()
    {
        swap(h[0], h[size() - 1]);
        h.pop_back();
        heapify();
    }

private:
    vector<int> h;

    int size() const
    {
        return SIZE(h);
    }

    int L(int i) const
    {
        return 2 * i + 1;
    }

    int R(int i) const
    {
        return 2 * i + 2;
    }

    int prev(int i) const
    {
        return (i - 1) / 2;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> code(n - 1);
    vector<int> cnt(n, 0);
    for (int i = 0; i < SIZE(code); i++) {
        cin >> code[i];
        code[i] -= 1;
        cnt[code[i]] += 1;
    }
    heap_t heap;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            heap.add(i);
        }
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < SIZE(code); i++) {
        cnt[code[i]]--;
        int u = heap.head();
        int v = code[i];
        heap.pop();
        g[u].push_back(v);
        g[v].push_back(u);
        if (cnt[code[i]] == 0)
            heap.add(code[i]);
    }
    for (auto row : g) {
        sort(begin(row), end(row));
        for (int i : row) cout << i + 1 << ' ';
        cout << "0\n";
    }
}
