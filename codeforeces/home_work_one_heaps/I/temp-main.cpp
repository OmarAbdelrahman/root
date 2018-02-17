#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

struct node {
    node* child;
    node* sibling;
    int val;
    int degree;

    node(const node*& n):
        child(n->child),
        sibling(n->sibling),
        val(n->val),
        degree(n->degree) { }

    node(node*&& n):
        child(move(n->child)),
        sibling(move(n->sibling)),
        val(move(n->val)),
        degree(move(n->degree))
    {
        n->child = nullptr;
        n->sibling = nullptr;
    }

    node(int _val): 
        child(nullptr),
        sibling(nullptr),
        val(_val),
        degree(0) { }

    static node* merge(node* a, node* b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        if (a->val < b->val)
            return merge(b, a);
        b->sibling = a->child;
        a->child = b;
        a->degree += 1;
        return a;
    }
};

struct heap {
    node* root = nullptr;

    heap(): root(nullptr) { }

    heap(int x): root(new node(x)) { }

    heap(node*& n): root(n) { }

    heap(node*&& n): root(move(n)) {
        n = nullptr;
    }

    heap(const heap*& h):
        root(h->root) { }

    heap(heap*&& h): root(move(h->root)) {
        h->root = nullptr;
    }

    void insert(int x) {
        root = merge(new heap(x))->root;
    }

    heap* merge(heap* other) {
        heap* h = new heap(merge(this, other));
        if (h->root == nullptr) {
            root = h->root;
            return h;
        }
        node* prev = nullptr;
        node* head = h->root;
        node* next = head->sibling;
        while (next != nullptr) {
            if (head->degree != next->degree || (next->sibling != nullptr && next->sibling->degree == head->degree)) {
                prev = head;
                head = next;
            } else if (head->val >= next->val) {
                head->sibling = next->sibling;
                head = node::merge(head, next);
            } else {
                if (prev == nullptr) {
                    h->root = next;
                } else {
                    prev->sibling = next;
                }
                next = node::merge(head, next);
                head = next;
            }
            next = next->sibling;
        }
        root = h->root;
        return h;
    }

    int pop() {
        if (root == nullptr) {
            return -INF;
        }
        int m = -INF;
        node* prev = nullptr;
        node* head = nullptr;
        node* head_prev = nullptr;
        for (node* itr = root; itr != nullptr; itr = itr->sibling) {
            if (head == nullptr || itr->val > m) {
                m = itr->val;
                head = itr;
                head_prev = prev;
            }
            prev = itr;
        }
        if (head == root) {
            root = head->sibling;
        } else {
            head_prev->sibling = head->sibling;
        }
        heap* h = new heap();
        node* without_max = head->child;
        while (without_max != nullptr) {
            node* next = without_max->sibling;
            without_max->sibling = h->root;
            h->root = without_max;
            without_max = next;
        }
        root = this->merge(h)->root;
        return m;
    }

private:
    node* merge(heap* h1, heap* h2) {
        if (h1->root == nullptr) return h2->root;
        if (h2->root == nullptr) return h1->root;

        node* new_root = nullptr;
        node* a = h1->root;
        node* b = h2->root;

        if (a->degree <= b->degree) {
            new_root = a;
            a = a->sibling;
        } else {
            new_root = b;
            b = b->sibling;
        }

        node* itr = new_root;
        while (a != nullptr && b != nullptr) {
            if (a->degree <= b->degree) {
                itr->sibling = a;
                a = a->sibling;
            } else {
                itr->sibling = b;
                b = b->sibling;
            }
            itr = itr->sibling;
        }

        if (a != nullptr)
            itr->sibling = a;
        else
            itr->sibling = b;

        return new_root;
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
