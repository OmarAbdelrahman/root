#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

int a[N];

int partition(int b, int e) {
    int i = b + 1;
    int pivot = a[b];
    for (int j = b + 1; j <= e; j++) {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i += 1;
        }
    }
    swap(a[b], a[i - 1]);
    return i - 1;
}

int rand_partition(int b, int e) {
    int pivot_pos = b + rand() % (e - b + 1);
    swap(a[pivot_pos], a[b]);
    return partition(b, e);
}

void sort(int b, int e) {
    if (b >= e) return;
    int pivot_pos = rand_partition(b, e);
    sort(b, pivot_pos - 1);
    sort(pivot_pos + 1, e);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
