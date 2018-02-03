#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

#define SIZE(a) (int) (a).size()

struct heap_t
{
    heap_t() { }

    heap_t(vector<pair<int, int>> _h): h(_h)
    {
        for (int i = SIZE(h) - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    void pop()
    {
        swap(h[0], h[size() - 1]);
        h.pop_back();
        heapify();
    }

    void add(pair<int, int> x)
    {
        h.push_back(x);
        push_up(size() - 1);
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
            pos = child;
        }
    }

    void push_up(int pos = 0)
    {
        while (pos != 0 && h[prev(pos)].first < h[pos].first) {
            swap(h[prev(pos)], h[pos]);
            pos = prev(pos);
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

    int size() const
    {
        return h.size();
    }

private:
    vector<pair<int, int>> h;

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

bool closed[N];
vector<int> s[N], e[N];
int c[N];

int main()
{
    int L, n;
    scanf("%d%d", &L, &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d%d", &a, &b, &c[i]);
        if (a == b) continue;
        s[a].push_back(i);
        e[b - 1].push_back(i);
    }
    heap_t heap;
    for (int i = 0; i < L; i++) {
        for (int x : s[i]) {
            heap.add({x, c[x]});
        }
        if (heap.size() > 0) {
            printf("%d ", heap.head().second);
        } else {
            printf("0 ");
        }
        for (int x : e[i]) closed[x] = true;
        while (heap.size() > 0 && closed[heap.head().first]) {
            heap.pop();
        }
    }
    printf("\n");
}
