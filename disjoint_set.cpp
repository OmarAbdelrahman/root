struct disjoint_set {
  int* parent;
  int* rank;
  int* set_size;
  int sets_count;

  disjoint_set() { }

  disjoint_set(int n) {
    initialize(n);
  }

  void initialize(int n) {
    parent = new int[n];
    rank = new int[n];
    set_size = new int[n];
    sets_count = n;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
      set_size[i] = 1;
    }
  }

  int operator [](int x) {
    if (parent[x] == x) return x;
    return (parent[x] = operator[](parent[x]));
  }

  void merge(int a, int b) {
    a = (*this)[a];
    b = (*this)[b];
    if (a == b) {
      return;
    }
    if (rank[a] == rank[b]) {
      rank[a]++;
    }
    if (rank[a] < rank[b]) {
      parent[a] = b;
      set_size[b] += set_size[a];
    }
    if (rank[a] > rank[b]) {
      parent[b] = a;
      set_size[a] += set_size[b];
    }
    sets_count--;
  }

  bool equal(int a, int b) {
    return (*this)[a] == (*this)[b];
  }

  ~disjoint_set() {
    delete[] parent;
    delete[] rank;
    delete[] set_size;
  }
};