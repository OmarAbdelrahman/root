#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

template<class T>
inline T next()
{
    T x;
    std::cin >> x;
    return x;
}

template<typename T>
struct heap_t
{
    heap_t(): heap_size(0) {}

    heap_t(const vector<T>& _a): a(_a), heap_size(_a.size())
    {
        for (int i = size() - 1; i >= 0; i--) heapify(i);
    }

    void add(const T& x)
    {
        a.push_back(x);
        heap_size += 1;
        int pos = size() - 1;
        while (pos != 0 && a[prev(pos)] < a[pos]) {
            swap(a[prev(pos)], a[pos]);
            pos = prev(pos);
        }
    }

    void heapify(int pos = 0)
    {
        while (pos < size()) {
            if (L(pos) >= size()) break;
            int child = L(pos);
            if (R(pos) < size() && a[child] < a[R(pos)]) {
                child++;
            }
            if (a[child] <= a[pos]) break;
            swap(a[child], a[pos]);
            pos = child;
        }
    }

    void sort()
    {
        while (size() >= 1) {
            swap(a.front(), a[size() - 1]);
            heap_size -= 1;
            heapify();
        }
        heap_size = SIZE(a);
    }

    T extract_max()
    {
        T value = head();
        swap(a.front(), a[size() - 1]);
        heap_size -= 1;
        heapify();
        return value;
    }

    T head() const
    {
        return a.front();
    }
    
    T& head()
    {
        return a[0];
    }

    int size() const
    {
        return heap_size;
    }

    friend ostream& operator << (ostream& ostr, const heap_t<T>& h)
    {
        for (int i = 0; i < h.size(); i++) {
            if (i > 0) ostr << ' ';
            ostr << h.a[i];
        }
        return ostr;
    }

private:
    vector<T> a;
    int heap_size;

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
    auto n = next<int>();
    heap_t<int> heap;
    for (int i = 0; i < n; i++) {
        auto s = next<int>();
        for (int j = 0; j < s; j++) {
            heap.add(next<int>());
        }
    }
    vector<int> result;
    while (heap.size() > 0) {
        result.push_back(heap.extract_max());
    }
    for (int i = SIZE(result) - 1; i >= 0; i--) {
        if (i < SIZE(result) - 1) cout << ' ';
        cout << result[i];
    }
    cout << '\n';
}
