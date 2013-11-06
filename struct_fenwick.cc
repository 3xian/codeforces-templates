template <typename T>
struct Fenwick {
  int  _n;
  T* _c;
  int  _d;

  Fenwick(int n) {
    _n = n;
    _c = (T*) calloc(n + 1, sizeof(T));
    _d = 1 << (31 - __builtin_clz(n));
  }
  ~Fenwick() {
    free(_c);
  }

  void modi(int p, const T& d) {
    for (; p <= _n; p += p & -p) _c[p] += d;
  }

  T sum(int p) const {
    T s = 0;
    for (; p > 0; p -= p & -p) s += _c[p];
    return s;
  }

  int operator [](int id) const {
    int p = 0;
    T s = 0;
    for (int i = _d; i > 0; i >>= 1) {
      if (p + i < _n && s + _c[p + i] <= id) {
        p += i;
        s += _c[p];
      }
    }
    return p + 1;
  }
};
