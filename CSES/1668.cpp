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
  vector<vector<int>> g(n + 1);
  vector<bool> vis(n + 1);
  vector<int> c(n + 1);
  for(int i = 0;i < m;i++){
    int a, b;cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i = 1;i <= n;i++){
    if(vis[i])continue;
    queue<pair<int, int>> q;
    q.push({i, 1});
    vis[i] = true;
    while(!q.empty()){
      int cur = q.front().first;
      int cur_c = q.front().second;
      q.pop();
      c[cur] = cur_c;
      for(auto adj : g[cur]){
        int nc = (cur_c == 1 ? 2 : 1);
        if(vis[adj]){
          if(c[adj] == cur_c){
            cout << "IMPOSSIBLE\n";
            return 0;
          }
          continue;
        }
        q.push({adj, nc});
        vis[adj] = true;
      }
    }
  }
  for(int i = 1;i <= n;i++){
    cout << c[i] << ' ';
  }
  cout << endl;
}
