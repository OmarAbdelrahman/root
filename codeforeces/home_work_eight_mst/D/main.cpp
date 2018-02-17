#include <bits/stdc++.h>
using namespace std;

const int M = (1 << 14) + 1;

char row[M];
int p[M * 2];

inline int from_hex(char c) {
    if (isdigit(c)) return c - '0';
    return c - 'A' + 10;
}

int find(int x) {
    return p[x] == x ? x : (p[x] = find(p[x]));
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a < b)
        p[b] = a;
    else
        p[a] = b;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < 2 * m; i++) {
        p[i] = -1;
    }
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", row);
        
        for (int j = 0; j < m; j++) {
            if (p[j] != -1) {
                p[j + m] = p[j] + m;
            } else {
                p[j + m] = -1;
            }
            p[j] = -1;
        }
        
        bool left = false;
        for (int j = 0; j < m; j++) {
            bool bit = (from_hex(row[j / 4]) >> ((j & 3) ^ 3)) & 1;
            if (bit) {
                p[j] = j;
                if (left) merge(j, j - 1);
                if (p[j + m] != -1) {
                    merge(j, j + m);
                }
            } else {
                p[j] = -1;
            }
            left = bit;
        }
        
        for (int j = m; j < 2 * m; j++)
            if (p[j] == j)
                result += 1;
    }
    
    for (int i = 0; i < m; i++)
        if (p[i] == i)
            result += 1;
    
    printf("%d\n", result);
}
