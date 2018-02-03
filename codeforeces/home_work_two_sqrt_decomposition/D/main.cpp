#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int a[N], cx[N], cm[N];
int k, n, m;

void relax(int j)
{
    if (cx[j] != -1) {
        for (int i = j * k; i < min(n, (j + 1) * k); i++) {
            a[i] = cx[j];
        }
        cx[j] = -1;
    }
}

void update_cm(int j)
{
    if (cx[j] == -1) { // not valid chunk
        cm[j] = *min_element(a + j * k, a + min(n, (j + 1) * k));
    }
}

void update(int b, int e, int val)
{
    relax(b / k);  // push values to chunk
    relax(e / k);
    for (int i = b; i <= e; ) {
        if (i % k == 0 && i + k - 1 <= e) {
            cx[i / k] = cm[i / k] = val;
            i += k;
        } else {
            a[i++] = val;
        }
    }
    update_cm(b / k);
    update_cm(e / k);
}

int rmq(int b, int e)
{
    int result = numeric_limits<int>::max();
    for (int i = b; i <= e; ) {
        if (i % k == 0 && i + k - 1 <= e) {
            result = min(result, cm[i / k]);
            i += k;
        } else {
            relax(i / k);
            result = min(result, a[i++]);
            // result = min(result, cx[i / k] == -1 ? a[i] : cx[i / k]); i++;
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    k = (int) sqrt(n * 1.0);
    m = (n + k - 1) / k;
    for (int i = 0; i < m; i++) {
        cm[i] = numeric_limits<int>::max();
        cx[i] = -1;
    }    
    for (int i = 0; i < n; i++) {
        cm[i / k] = min(cm[i / k], a[i]);
    }

    int q;
    cin >> q;
    while (q-- > 0) {
        int t, x, y, z;
        cin >> t;
        if (t == 1) {
            cin >> x >> y;
            cout << rmq(x - 1, y - 1) << '\n';
        } else {
            cin >> x >> y >> z;
            update(x - 1, y - 1, z);
        }
    }
}
