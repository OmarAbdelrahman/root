#include <bits/stdc++.h>
using namespace std;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

struct heap {
    heap(): heap_size(0) { }

    void heapify(int pos = 0) {
        while (pos < size()) {
            int child = L(pos);
            if (child >= size()) break;
            if (R(pos) < size() && h[R(pos)] > h[child]) {
                child += 1;
            }
            if (h[pos] >= h[child]) break;
            swap(h[pos], h[child]);
            pos = child;
        }
    }

    void add(int x) {
        h.push_back(x);
        heap_size += 1;
        int pos = size() - 1;
        while (pos != 0 && h[prev(pos)] < h[pos]) {
            swap(h[prev(pos)], h[pos]);
            pos = prev(pos);
        }
    }

    int top() {
        return h.front();
    }

    void extract() {
        swap(h.front(), h.back());
        h.pop_back();
        heap_size -= 1;
        heapify();
    }

    int size() const {
        return heap_size;
    }

private:
    vector<int> h;
    int heap_size;

    int prev(int i) const {
        return (i - 1) / 2;
    }

    int L(int i) const {
        return 2 * i + 1;
    }

    int R(int i) const {
        return 2 * i + 2;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    heap h;
    vector<vector<int>> r;
    
    while (t-- > 0) {
        int x;
        cin >> x;
        h.add(x);
        if (h.size() < 3) {
            cout << "-1\n";
            continue;
        }
        vector<int> v;
        for (int i = 0; i < 3; i++) {
            v.push_back(h.top());
            h.extract();
        }
        for (int i = 0; i < 3; i++) {
            h.add(v[i]);
            cout << v[i] << " \n"[i == 2];
        }
    }
}
