#define L (I<<1)
#define R (I<<1|1)

bool change[S*4];

inline void push(int I) {
    if (change[I]) {
        change[I] = false;
        change[L] = true;
        change[R] = true;
        //<<<
        val[L] = val[I];
        val[R] = val[I];
        //>>>
    }
}
inline void merge(int I) {
    //<<<
    val[I] = val[L] < val[R] ? val[L] : val[R];
    //>>>
}
void update(int I, int l, int r, int p, const Value& v) {
    if (l == r) {
        //<<<
        val[I] = v;
        //>>>
        return;
    }
    push(I);
    int m = l + r >> 1;
    if (p <= m) update(L, l, m, p, v);
    else update(R, m+1, r, p, v);
    merge(I);
}
void range_update(int I, int l, int r, int x, int y, const Value& v) {
    if (l == x and r == y) {
        change[I] = true;
        //<<<
        val[I] = v;
        //>>>
        return;
    }
    push(I);
    int m = l + r >> 1;
    if (y <= m) range_update(L, l, m, x, y, v);
    else if (x > m) range_update(R, m+1, r, x, y, v);
    else {
        range_update(L, l, m, x, m, v);
        range_update(R, m+1, r, m+1, y, v);
    }
    merge(I);
}
Value query(int I, int l, int r, int p) {
    if (l == r) {
        //<<<
        return val[I];
        //>>>
    }
    push(I);
    int m = l + r >> 1;
    if (p <= m) return query(L, l, m, p);
    else return query(R, m+1, r, p);
}
Value range_query(int I, int l, int r, int x, int y) {
    if (l == x and r == y) {
        //<<<
        return val[I];
        //>>>
    }
    push(I);
    int m = l + r >> 1;
    Value res;
    if (y <= m) {
        res = range_query(L, l, m, x, y);
    } else if (x > m) {
        res = range_query(R, m+1, r, x, y);
    } else {
        Value a = range_query(L, l, m, x, m);
        Value b = range_query(R, m+1, r, m+1, y);
        //<<<
        res = min(a, b);
        //>>>
    }
    return res;
}
