#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define logging(x)
#else
#define logging(x) cout<<"\033[31m ---> "#x" = "<<x<<'\n'
#endif
using namespace std;
struct SpeedUp{ SpeedUp() { ios::sync_with_stdio(false); cin.tie(NULL); } } _;
string ToString(int i) { char s[16]; sprintf(s, "%d", i); return s; };
template<typename T>
void Unique(vector<T>& a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); };

int main() {
  return 0;
}
