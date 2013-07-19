#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
#define range(i, n) for (int i=0; i<(n); ++i)
#ifdef ONLINE_JUDGE
#define logging(x)
#else
#define logging(x) cerr << #x":" << x << endl
#endif
#define tpl_t template<typename T>
#define stream(a) string _##a; getline(cin, _##a); stringstream a(_##a);
using namespace std;
int d4[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
tpl_t void lmax(T& a, const T& b) { if (a < b) a = b; }
tpl_t void lmin(T& a, const T& b) { if (a > b) a = b; }
tpl_t void usort(vector<T>& a) { sort(all(a)); a.erase(unique(a.begin(),a.end()),a.end()); }
tpl_t void operator +=(vector<T>& v, const T& x) { v.push_back(x); }
string str(int i) { char s[16]; sprintf(s,"%d",i); return s; }
//...ooo000...ooo000...ooo000...ooo000...ooo000...ooo000...ooo000...ooo000...ooo000...ooo000

int main() {
	ios::sync_with_stdio(false);
	return 0;
}
