#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

struct heap_t
{
    heap_t(vector<pair<int, int>> _h): h(_h)
    {
        heap_pos.resize(SIZE(h), -1);
        for (int i = SIZE(h) - 1; i >= 0; i--) {
            heapify(i);
        }
        for (int i = 0; i < SIZE(h); i++) {
            heap_pos[h[i].second] = i;
        }
    }

    void heapify(int pos = 0)
    {
        while (pos < size()) {
            int child = L(pos);
            if (child >= size()) break;
            if (R(pos) < size() && h[R(pos)].first > h[child].first) {
                child++;
            }
            if (h[child].first <= h[pos].first) break;
            swap(h[child], h[pos]);
            heap_pos[h[child].second] = child;
            heap_pos[h[pos].second] = pos;
            pos = child;
        }
    }

    void push_up(int pos = 0)
    {
        while (pos != 0 && h[prev(pos)].first < h[pos].first) {
            swap(h[prev(pos)], h[pos]);
            heap_pos[h[prev(pos)].second] = prev(pos);
            heap_pos[h[pos].second] = pos;
            pos = prev(pos);
        }
    }

    void modify(int i, int x)
    {
        if (h[heap_pos[i]].first > x) {
            h[heap_pos[i]].first = x;
            heapify(heap_pos[i]);
        } else {
            h[heap_pos[i]].first = x;
            push_up(heap_pos[i]);
        }
    }
    
    pair<int, int> head() const
    {
        return h[0];
    }

    pair<int, int>& head()
    {
        return h[0];
    }

private:
    vector<pair<int, int>> h;
    vector<int> heap_pos;

    int size() const
    {
        return h.size();
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
    int n, c;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    heap_t heap(a);
    int os, i, j;
    scanf("%d", &os);
    while (os-- > 0) {
        scanf("%d", &c);
        if (c == 1) {
            printf("%d\n", heap.head().first);
        } else {
            scanf("%d%d", &i, &j);
            heap.modify(i - 1, j);
        }
    }
}
