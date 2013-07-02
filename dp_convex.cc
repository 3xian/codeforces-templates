// 单调队列优化
// 把两个状态a和b分别带入状态c的递推式（a < b），化为除法式表示什么情况下a比b好，使左值只跟a和b有关，右值只跟c有关。
// "x(a,b) / y(a,b) < z(c)" or "slope(a,b) < z(c)"
// 若 z(c) 单调（b 永远比 a 优秀），就可以使用单调队列进行优化。
//
// 第一：根据斜率剔除队头的废物，取最优解
// 第二：维护凸性
// if slope(tail-1,tail) > slope(tail,i), kick tail
//
// 易错点：
// - 除了队列之外还有转移来源
// - 溢出
// - 乘除负数导致不等号变号

double slope(int x, int y) {
	return (double)(f[y]-f[x]) / (b[x]-b[y]);
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	range (i, n) { cin >> a[i]; }
	range (i, n) { cin >> b[i]; }

	q[0] = 0;
	int head = 0;
	int tail = 0;
	for (int i = 1; i < n; ++i) {
		while (head < tail and slope(q[head], q[head+1]) <= a[i]) ++head;
		int x = q[head];
		f[i] = f[x] + (long long)b[x] * a[i];
		while (head < tail and slope(q[tail-1], q[tail]) >= slope(q[tail], i)) --tail;
		q[++tail] = i;
	}
	cout << f[n-1];
	return 0;
}
