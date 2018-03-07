#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;

struct node {
    node* parent = nullptr;
    node* child = nullptr;
    node* sibling = nullptr;
    int key;
    int degree;

    node(int k):
        parent(nullptr),
        child(nullptr),
        sibling(nullptr),
        key(k),
        degree(0) { }
};

struct heap {
    node* root = nullptr;

    node* top() {
        node* y = nullptr;
        int m = INF;
        for (node* x = root; x != nullptr; x = x->sibling) {
            if (x->key > m) {
                m = x->key;
                y = x;
            }
        }
        return y;
    }

    void merge(heap* h1, heap* h2) {
        
    }

    void link(node*& y, node*& z) {
        y->parent = z;
        y->sibling = z->child;
        z->child = y;
        z->degree += 1;
    }
};

heap* heaps[1000010];

int main() {
    int q;
    scanf("%d", &q);

    int id = 0;
    char cmd[10];

    while (q-- > 0) {
        scanf("%s", cmd);
        if (strcmp(cmd, "new") == 0)  {
            heaps[id++] = new heap();
        } else if (strcmp(cmd, "push") == 0) {
            int i, d;
            scanf("%d%d", &i, &d);
            heaps[i - 1]->insert(d);
        } else if (strcmp(cmd, "pop") == 0) {
            int i;
            scanf("%d", &i);
            printf("%d\n", heaps[i - 1]->pop());
        } else {
            int i, j;
            scanf("%d%d", &i, &j);
            heaps[id++] = heaps[i - 1]->merge(heaps[j - 1]);
        }
    }
}
