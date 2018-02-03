#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;

vector<int> a;
vector<int> c;
int k;

void update(int pos, int val)
{
    c[pos / k] -= a[pos];
    a[pos] = val;
    c[pos / k] += a[pos];
}

int rsq(int b, int e)
{
    int result = 0;
    for (int i = b; i <= e; ) {
        if (i % k == 0 && i + k - 1 <= e) {
            result += c[i / k];
            i += k;
        } else {
            result += a[i++];
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    k = (int) sqrt(N * 1.0);
    c = vector<int>((N + k - 1) / k);
    a = vector<int>(N);

    int n;
    cin >> n;

    long long result = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        result += rsq(v + 1, N);
        update(v, 1);
    }
    cout << result << '\n';
}