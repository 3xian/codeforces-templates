class Matrix:
    def __init__(self, rows): self.rows = copy.deepcopy(rows)
    def __getitem__(self, i): return self.rows[i]
    def __repr__(self): return '\n'.join(map(str, self.rows))

    def unit(self):
        n = len(self.rows)
        mat = [[0] * n for i in range(n)]
        for i in xrange(n): mat[i][i] = 1
        return Matrix(mat)

    def mul(self, other, mod=None):
        n = len(other.rows)
        m = len(other.rows[0])
        trans = zip(*other.rows)
        ret = [[0] * m for i in range(n)]
        for i, row in enumerate(ret):
            for j in xrange(m):
                a, b, t = self.rows[i], trans[j], 0
                for k in xrange(n): t += a[k] * b[k]
                row[j] = t % mod if mod else t
        return Matrix(ret)

    def pow(self, k, mod=None):
        a = Matrix(self.rows)
        r = self.unit()
        while k > 0:
            if k & 1: r = r.mul(a, mod)
            if k > 1: a = a.mul(a, mod)
            k >>= 1
        return r

    def sum(self):
        return sum(sum(r) for r in self.rows)
