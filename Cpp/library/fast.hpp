// doot diddly donger cuckerino Hahahahahah
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define PB              push_back
#define EB              emplace_back
#define F               first
#define S               second
#define all(a)          (a).begin(),(a).end()
#define sz(x)           (int)(x).size()
#define REP(x, n)       for(ll x = 0; x < n; ++x)
#define Unique(x)       sort(all(x)); (x).erase(unique(all(x), (x).end()));
#define IOS             ios::sync_with_stdio(false);cin.tie(NULL); cout << fixed << setprecision(12)
#define IN_REP          int tt; cin >> tt; while(tt--)
#define FORE(x, a)      for_each(all(a), [](auto& x)
#define sim             template<class T
#define ris             return * this
#define dor             > debug & operator <<
#define eni(x)          sim > typename enable_if<sizeof dud<T>(0) x 1, debug&>::type operator<<(T i)
sim> struct rge { T b, e; };
sim> rge<T> range(T i, T j) { return rge<T>{i, j}; }
sim> auto dud(T *x) -> decltype(cout << *x, 0);
sim> char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
  eni(!=) {
      cout << boolalpha << i;
      ris;
  }
  eni(==) { ris << range(all(i)); }
  sim, class U dor(pair<U, T> d) { ris << "(" << d.first << ", " << d.second << ")"; }
  sim dor(rge<T> d) {
      *this << "[";
      for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
      ris << "]";
  }
#else
  sim dor(const T&) { ris; }
#endif
};
#define pr(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ld EPS = (ld) 1e-9;
const ll MOD = (ll) 998244353;
const ld PI = acos(-1);

sim> T gcd(T x, T y) { return (y == 0) ? x : gcd(y, x % y); }
sim> void mini(T& x, T y) { x = min(x, y); }
sim> void maxi(T& x, T y) { x = max(x, y); }
sim, class U> string to_string(pair<T, U> p) { return to_string(p.F) + " " + to_string(p.S); }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
