#include <bits/stdc++.h>
using namespace std;

struct node_t
{
    node_t* L;
    node_t* R;
    int value;

    node_t(const int& v): L(nullptr), R(nullptr), value(v)
    {
    }
};

node_t* merge(node_t* a, node_t* b)
{
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    if (a->value < b->value) {
        return merge(b, a);
    }
    if (rand() % 2) {
        a->L = merge(a->L, b);
    } else {
        a->R = merge(a->R, b);
    }
    return a;
}

void extract_max(node_t*& root)
{
    if (root == nullptr) return;
    root = merge(root->L, root->R);
}

node_t* heaps[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, i, j;
    cin >> m;
    int id = 0;
    string cmd;
    while (m-- > 0) {
        cin >> cmd;
        char c = cmd.back();
        if (c == 'w') {
            heaps[id++] = nullptr;
        } else if (c == 'h') {
            cin >> i >> j;
            i -= 1;
            heaps[i] = merge(heaps[i], new node_t(j));
        } else if (c == 'p') {
            cin >> i;
            i -= 1;
            cout << heaps[i]->value << '\n';
            extract_max(heaps[i]);
        } else if (c == 'e') {
            cin >> i >> j;
            heaps[id++] = merge(heaps[i - 1], heaps[j - 1]);
        }
    }
}
