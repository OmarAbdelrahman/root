#include <bits/stdc++.h>
using namespace std;

template<typename T>
inline T next()
{
    T x;
    std::cin >> x;
    return x;
}

template<typename T>
struct heap_t
{
    vector<T> a;
    vector<pair<int, int>> swap_indices;

    heap_t() { }

    heap_t(int _size): a(_size)
    {
        for (T& it : a) {
            cin >> it;
        }
        for (int i = size() - 1; i >= 0; --i) {
            heapify(i);
        }
    }

    void heapify(int pos)
    {
        while (pos < size()) {
            if (L(pos) >= size()) break;
            int child = L(pos);
            if (R(pos) < size() && a[child] < a[R(pos)]) {
                child++;
            }
            if (a[child] <= a[pos]) break;
            swap(a[child], a[pos]);
            swap_indices.push_back({pos, child});
            pos = child;
        }
    }

    int size() const
    {
        return a.size();
    }

private:
    int L(int i) const
    {
        return 2 * i + 1;
    }

    int R(int i) const
    {
        return 2 * i + 2;
    }

    void print() const
    {
        for (int i = 0; i < size(); i++) {
            if (i > 0) cerr << ' ';
            cerr << a[i];
        }
        cerr << '\n';
    }
};

template<typename T>
ostream& operator << (ostream& ostr, const heap_t<T>& h)
{
    ostr << h.swap_indices.size() << '\n';
    for (const auto& p : h.swap_indices) {
        ostr << p.first << ' ' << p.second << '\n';
    }
    for (int i = 0; i < h.size(); i++) {
        if (i > 0) ostr << ' ';
        ostr << h.a[i];
    }
    return ostr;
}

int main()
{
    cout << heap_t<int>(next<int>()) << '\n';
}
