#include <bits/stdc++.h>
using namespace std;

const int M = 123456;
const long long K = (long long) 1e18;

template<class T>
inline T next() {
    T x;
    cin >> x;
    return x;
}

const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string f1 = "What are you doing while sending \"" + f0 + "\"? Are you busy? Will you send \"" + f0 + "\"?";

const string A = "What are you doing while sending \"";
const string B = "\"? Are you busy? Will you send \"";
const string C = "\"?";

const int a = (int) A.length();
const int b = (int) B.length();
const int c = (int) C.length();

long long lengths[M];

void fill_lengths() {
    lengths[0] = (long long) f0.length();
    for (int i = 1; i < M; i++) {
        lengths[i] = min(K, a + lengths[i - 1] + b + lengths[i - 1] + c);
    }
}

char solve(int n, int k) {
    if (lengths[n] <= k) return '.';
    return '';
}

int main() {
    fill_lengths();
    auto q = next<int>();
    int n, k;
    while (q-- > 0) {
        cin >> n >> k;
        cout << solve(n, k - 1) << endl;
    }
    return 0;
}
