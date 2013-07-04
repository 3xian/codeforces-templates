def inverse(a, m):
    b = m
    u = 1
    v = 0
    while b != 0:
        t = a / b
        a, b = b, a - t * b
        u, v = v, u - t * v
    return (u % m + m) % m;
