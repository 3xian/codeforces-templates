#include <bits/stdc++.h>
#define vec std::vector
#define whole(a) (a).begin(),(a).end()
using namespace std;
void setio() { ios::sync_with_stdio(0); cin.tie(0); }
string itos(int value) { char buf[12]; sprintf(buf, "%d", value); return buf; }
template<class T> void uniq(vec<T>& a){ sort(whole(a)); a.erase(unique(whole(a)), a.end()); }
template<class T> void operator +=(vec<T> &a, const T& x){ a.push_back(x); }

int main() {
    setio();
    // Start here
    return 0;
}
