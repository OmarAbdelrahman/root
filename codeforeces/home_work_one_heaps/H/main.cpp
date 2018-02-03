#include <bits/stdc++.h>
using namespace std;

struct node_t
{
    node_t* child;
    node_t* sibling;
    int value;

    node_t(const int& v): child(nullptr), sibling(nullptr), value(v)
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
    b->sibling = a->child;
    a->child = b;
    return a;
}

node_t* compress(node_t* root)
{
    if (root == nullptr || root->sibling == nullptr) return root;
    return merge(merge(root, root->sibling), compress(root->sibling->sibling));
}

void extract_max(node_t*& root)
{
    if (root == nullptr) return;
    node_t* without_max = root->child;
    delete root;
    root = compress(without_max);
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
