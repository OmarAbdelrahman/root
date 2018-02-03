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
    int swaps;

    heap_t() { }

    heap_t(int _size): swaps(0), a(_size), heap_size(_size)
    {
        for (T& it : a) cin >> it;
        for (int i = size() - 1; i >= 0; --i) {
            heapify(i);
        }
    }

    void heapify(int pos = 0)
    {
        while (pos < size()) {
            if(L(pos) >= size()) break;
            int child = L(pos);
            if (R(pos) < size() && a[child] < a[R(pos)]) {
                child++;
            }
            if (a[child] <= a[pos]) break;
            swap(a[child], a[pos]);
            swaps += 1;
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

    int size() const
    {
        return heap_size;
    }

    friend ostream& operator << (ostream& ostr, const heap_t<T>& h)
    {
        ostr << h.swaps << '\n';
        for (int i = 0; i < SIZE(h.a); i++) {
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
};

int main()
{
    heap_t<int> heap(next<int>());
    heap.sort();
    cout << heap << '\n';
}