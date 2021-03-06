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

  int t;cin >> t;
  while(t--){
    int a, b, k;cin >> a >> b >> k;
    int g = __gcd(a, b);
    bool valid = true;
    int na = a, nb = b;
    int sa = 0, sb = 0;
    for(int i = 2;i * i <= na;i++){
      while(na % i == 0){
        sa++;
        na /= i;
      }
    }
    if(na > 1)sa++;
    for(int i = 2;i * i <= nb;i++){
      while(nb % i == 0){
        sb++;
        nb /= i;
      }
    }
    if(nb > 1)sb++;
    //k is too big
    if(k > sa + sb)valid = false;
    //k is too small
    if(a != g && b != g && k == 1)valid = false;
    if(a == g && b == g && k == 1)valid = false;
    if(valid)cout << "YES";
    else cout << "NO";
    cout << endl;
  }
}
