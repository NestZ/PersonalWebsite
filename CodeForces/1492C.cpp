#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;cin >> n >> m;
  string sn;cin >> sn;
  string sm;cin >> sm;
  map<int, int> fst, lst;
  int ptr = m - 1;
  for(int i = n - 1;i >= 0;i--){
    if(sn[i] == sm[ptr]){
      lst[ptr] = i;
      ptr--;
    }
  }
  assert(ptr == -1);
  ptr = 0;
  for(int i = 0;i < n;i++){
    if(sn[i] == sm[ptr]){
      fst[ptr] = i;
      ptr++;
    }
  }
  assert(ptr == m);
  int ans = 0;
  for(int i = 1;i < m;i++){
    ans = max(ans, lst[i] - fst[i - 1]);
  }
  cout << ans << endl;
}
