// "Template"==================================================
// "prefix": "temp",
// "description": "C++テンプレート"
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define l_rot(x) rotate(x.begin(),x.begin()+1,x.end());
#define r_rot(x) rotate(x.rbegin(),x.rbegin()+1,x.rend());
#define sz(x) (int)((x).size())
#define fo(x) cout<<x<<endl
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vp vector<P>
#define vvp vector<vp>
#define vt vector<tuple<int,int,int>>
#define vs vector<string>
#define vm vector<mint>
#define vvm vector<vm>
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define ppcll __builtin_popcountll
int my_ceil(int a, int b){return (a+(b-1))/b;}
int my_ceil_pm(int a, int b){return ((a*b>0?1:-1)*(abs(a)+(abs(b)-1)))/abs(b);}
auto my_max(auto a, auto b){return a<b?b:a;}
auto my_min(auto a, auto b){return a<b?a:b;}
int gcd(int a, int b){return b?gcd(b,a%b):a;}
int lcm(int a, int b){return a*b/gcd(a,b);}
void dec_all(vi &A){ rep(i,0,sz(A)) A[i]--;}
template <typename T> bool chmin(T &a, const T& b){if(a>b){a=b; return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a<b){a=b; return true;}return false;}
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

const long long INF=1e18;//8e18;

signed main(){
  int N;
  cin >> N;
  vi A(N);
  rep(i,0,N) cin >> A[i];

  vi A(N),B(N);
  rep(i,0,N) cin >> A[i];
  rep(i,0,N) cin >> B[i];

  vi A(N),B(N);
  rep(i,0,N) cin >> A[i] >> B[i];

  printf("%.10lf\n",ans);
}

// "out_vec_with_space"==================================================
// "prefix": "out_vec_with_space",
// "description": "配列をスペース区切りで出力",
void out_vec_with_space(vector<auto> &v){
  for (int i = 0; i < v.size(); i++){
    cout << ( i ? " " : "" ) << v[i];
  }
  cout << endl;
}

// "out_vec2_with_space"==================================================
//  "prefix": "out_vec2_with_space",
//  "description": "2次元配列をスペース区切りで出力",
void out_vec2_with_space(vector<vector<auto>> &v){
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[0].size(); j++){
      cout << ( j ? " " : "" ) << v[i][j];
    }
    cout << endl;    
  }
}

// "bit全探索"==================================================
// "prefix": "bit_zentansaku",
// "description": "bit全探索"
rep(bit,0,1<<N){
  rep(i,0,N){
    if(bit>>i & 1){
      // 処理
    }
  }
}

// "二分探索"==================================================
// "prefix": "nibuntansaku",
// "description": "二分探索"
int l=0,r=INF;
while(r-l>1){
  int mid=(l+r)/2;
  if(f(mid)) l=mid;
  else r=mid;
}

// "座標圧縮"==================================================
// "prefix": "compress",
// "description": "座標圧縮"
vi compress(vi A) {
  map<int,int> mp;
  vi res(sz(A));
  rep(i,0,sz(A)) mp[A[i]]=0; // mapに元の配列を入れる
  int i=0;
  fore(x,mp) x.second = i++; // 順番を付ける
  rep(i,0,sz(A)) res[i] = mp[A[i]]; // 元の配列を順番にする
  return res;
}

// "Union-Find"==================================================
// "prefix": "unionFind",
// "description": "Union-Find"
struct UnionFind {
  vector<int> par, siz;
  int component; // グループ数
  UnionFind(int n) : par(n, -1), siz(n, 1), component(n) { }
  int root(int x) {
    if (par[x] == -1) return x;
    else return par[x] = root(par[x]);
  }
  bool issame(int x, int y) {
    return root(x) == root(y);
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    // すでに同じグループのときは何もしない
    if (x == y) return false;
    // union by size (y側のサイズが小さくなるようにする)
    if(siz[x] < siz[y]) swap(x, y);
    // yをxの子とする
    par[y] = x;
    siz[x] += siz[y];
    component--;
    return true;
  }
  int size(int x){
    return siz[root(x)];
  }
};

// "Union-Find-use"==================================================
// "prefix": "unionFindUse",
// "description": "Union-Findの使用例"
UnionFind uf(5); // 0,1,2,3,4の要素を作る
//uf.root(1); // 要素1の根を返す
//uf.issame(0,2); // 0と2が同じ要素か判定
//uf.unite(0,2); // 0と2の要素を結合
//uf.size(0); // 要素0の属するグループのサイズを返す

// "ModInt"==================================================
// "prefix": "mint",
// "description": "ModInt"
//const int mod = 1000000007;
const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  bool operator==(auto a) const { return x == a; } // 210822 ABC215Eで追加
  bool operator!=(auto a) const { return x != a; } // 210822 ABC215Eで追加
  //bool operator<(const mint a) const{return mint(*this)<a;} // 211119 ABC151Eで追加
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

// "Mint-use"==================================================
// "prefix": "mintUse",
// "description": "Mintの使用例"
// ansを出力
mint ans = 0;
ans = 10;
cout << ans.x << endl;

// 2の5乗を計算
mint ans2 = mint(2).pow(5);
cout << ans2.x << endl;

// 2の逆元
mint div = mint(2).pow(mod-2);

// "Mint-Comb"==================================================
// "prefix": "mintComb",
// "description": "mint-comb(mintのコード含む)"
//const int mod = 1000000007;
const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  bool operator==(auto a) const { return x == a; } // 210822 ABC215Eで追加
  bool operator!=(auto a) const { return x != a; } // 210822 ABC215Eで追加
  //bool operator<(const mint a) const{return mint(*this)<a;} // 211119 ABC151Eで追加
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
} c(2000005);
// 重複組み合わせ(種類数-1の仕切りを混ぜて、仕切りを選ぶ事に相当) nHr=n+r-1Cr
// n種類のボールが無限にある,そこから重複ありでr個のボールを選ぶ(元の意味)
mint h(int n, int r){return c(n+r-1,r);}
// n個のボールをrグループに分ける,但しグループ内は0個を許容する
mint h1(int n, int r){return c(n+r-1,r-1);}
// n個のボールをrグループに分ける,但しグループ内は1個以上(上の式のnをn-rに変更している)
mint h2(int n, int r){return c(n-1,r-1);}

// ARC134C https://atcoder.jp/contests/arc134/submissions/30218193より
// nが大きい場合
// nCr % mod を計算する O(r)
mint combmod(ll n, ll r) {
  mint x=1,y=1;
  r=min(n-r,r);
  rep(i,0,r){x*=(n-i);} // 分子
  rep(i,1,r+1){y*=i;}   // 分母
  return x*y.inv();     // nCr=(分子)/(分母)
}

// "MintComb-use"==================================================
// "prefix": "mintCombUse",
// "description": "mint-combの使用例"
//combination c(m+n); // グローバルで宣言するようにした
mint ans = c(m+n,m);
mint ans=combmod(A[i]+K-1,K-1);

// "ModPow"==================================================
// "prefix": "mintPow",
// "description": "繰り返し二乗法"
int mintPow(int a, int n, int m) {
  if(n==0) return 1; // 0乗にも対応する場合
  if(n==1) return a%m;
  if(n%2==1) return (a*mintPow(a,n-1,m))%m;
  int t=mintPow(a,n/2,m);
  return (t*t)%m;
}

// "GetDigit"==================================================
// "prefix": "getDigit",
// "description": "桁数を求める"
int get_digit(int num){
  int res=0;
  while(num){
    num/=10;
    ++res;
  }
  return res;
}

// "SegmentTree"==================================================
// "prefix": "segTree",
// "description": "セグ木"
// segtreeにこれも必要
int ceil_pow2(int n){
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}

template <class S, S (*op)(S, S), S (*e)()>
struct segtree{
public:
  segtree() : segtree(0) {}
  segtree(int n) : segtree(std::vector<S>(n, e())) {}
  segtree(const std::vector<S> &v) : _n(ll(v.size())){
    log = ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) update(i);
  }

  void set(int p, S x){
    assert(0 <= p && p < _n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  S get(int p){
    assert(0 <= p && p < _n);
    return d[p + size];
  }

  S prod(int l, int r){
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;

    while (l < r){
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  template <bool (*f)(S)>
  int max_right(int l){
    return max_right(l, [](S x){ return f(x); });
  }
  template <class F>
  int max_right(int l, F f){
    assert(0 <= l && l <= _n);
    assert(f(e()));
    if (l == _n) return _n;
    l += size;
    S sm = e();
    do{
      while (l % 2 == 0) l >>= 1;
      if (!f(op(sm, d[l]))){
        while (l < size){
          l = (2 * l);
          if (f(op(sm, d[l]))){
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*f)(S)>
  int min_left(int r){
    return min_left(r, [](S x){ return f(x); });
  }
  template <class F>
  int min_left(int r, F f){
    assert(0 <= r && r <= _n);
    assert(f(e()));
    if (r == 0) return 0;
    r += size;
    S sm = e();
    do{
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!f(op(d[r], sm))){
        while (r < size){
          r = (2 * r + 1);
          if (f(op(d[r], sm))){
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

private:
  int _n, size, log;
  std::vector<S> d;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

// range minimize query
// range maximize query
// range add query
// range update query

// RMQ(RangeMinimumQuery)
//int op(int a,int b){return my_min(a,b);}
//int e(){return INF;}

// RMQ(RangeMaxQuery)
int op(int a,int b){return my_max(a,b);}
int e(){return 0;}

// RSQ(RangeSumQuery)
//int op(int a,int b){return a+b;}
//int e(){return 0;}

// GCDを乗せる
int op(int a,int b){return gcd(a,b);}
int e(){return 0;}

// xorを乗せる
int op(int a,int b){return a^b;}
int e(){return 0;}



// "SegmentTree-use"
// "prefix": "segTreeUse",
// "description": "セグ木の使い方"
segtree<int,op,e> seg(N); // 要素数で初期化
//segtree<int,op,e> seg(A); // 配列で初期化

int p,x,l,r;
seg.set(p, x); // a[p]にxを代入
int n1 = seg.get(p); // a[p]を取得
int n2 = seg.prod(l,r); // op(a[l]...a[r-1])を計算
int n3 = seg.all_prod(); // op(a[l]...a[n-1])を計算
// max_right // まだ理解していない
// min_left // まだ理解していない

  "LazySegmentTree": {
    "prefix": "lazySegTree",
    "body": [
      "unsigned int bit_ceil(unsigned int n) {",
      "  unsigned int x = 1;",
      "  while (x < (unsigned int)(n)) x *= 2;",
      "  return x;",
      "}",
      "int countr_zero(unsigned int n) {",
      "  return __builtin_ctz(n);",
      "}",
      "constexpr int countr_zero_constexpr(unsigned int n) {",
      "  int x = 0;",
      "  while (!(n & (1 << x))) x++;",
      "  return x;",
      "}",
      "",
      "template <class S,",
      "          S (*op)(S, S),",
      "          S (*e)(),",
      "          class F,",
      "          S (*mapping)(F, S),",
      "          F (*composition)(F, F),",
      "          F (*id)()>",
      "struct lazy_segtree {",
      "public:",
      "  lazy_segtree() : lazy_segtree(0) {}",
      "  explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n, e())) {}",
      "  explicit lazy_segtree(const vector<S>& v) : _n((v.size())) {",
      "    size = (int)bit_ceil((unsigned int)(_n));",
      "    log = countr_zero((unsigned int)size);",
      "    d = vector<S>(2 * size, e());",
      "    lz = vector<F>(size, id());",
      "    for (int i = 0; i < _n; i++) d[size + i] = v[i];",
      "    for (int i = size - 1; i >= 1; i--) {",
      "      update(i);",
      "    }",
      "  }",
      "  void set(int p, S x) {",
      "    assert(0 <= p && p < _n);",
      "    p += size;",
      "    for (int i = log; i >= 1; i--) push(p >> i);",
      "    d[p] = x;",
      "    for (int i = 1; i <= log; i++) update(p >> i);",
      "  }",
      "  S get(int p) {",
      "    assert(0 <= p && p < _n);",
      "    p += size;",
      "    for (int i = log; i >= 1; i--) push(p >> i);",
      "    return d[p];",
      "  }",
      "  S prod(int l, int r) {",
      "    assert(0 <= l && l <= r && r <= _n);",
      "    if (l == r) return e();",
      "    l += size;",
      "    r += size;",
      "    for (int i = log; i >= 1; i--) {",
      "      if (((l >> i) << i) != l) push(l >> i);",
      "      if (((r >> i) << i) != r) push((r - 1) >> i);",
      "    }",
      "    S sml = e(), smr = e();",
      "    while (l < r) {",
      "      if (l & 1) sml = op(sml, d[l++]);",
      "      if (r & 1) smr = op(d[--r], smr);",
      "      l >>= 1;",
      "      r >>= 1;",
      "    }",
      "    return op(sml, smr);",
      "  }",
      "  S all_prod() { return d[1]; }",
      "  void apply(int p, F f) {",
      "    assert(0 <= p && p < _n);",
      "    p += size;",
      "    for (int i = log; i >= 1; i--) push(p >> i);",
      "    d[p] = mapping(f, d[p]);",
      "    for (int i = 1; i <= log; i++) update(p >> i);",
      "  }",
      "  void apply(int l, int r, F f) {",
      "    assert(0 <= l && l <= r && r <= _n);",
      "    if (l == r) return;",
      "    l += size;",
      "    r += size;",
      "    for (int i = log; i >= 1; i--) {",
      "      if (((l >> i) << i) != l) push(l >> i);",
      "      if (((r >> i) << i) != r) push((r - 1) >> i);",
      "    }",
      "    {",
      "      int l2 = l, r2 = r;",
      "      while (l < r) {",
      "        if (l & 1) all_apply(l++, f);",
      "        if (r & 1) all_apply(--r, f);",
      "        l >>= 1;",
      "        r >>= 1;",
      "      }",
      "      l = l2;",
      "      r = r2;",
      "    }",
      "    for (int i = 1; i <= log; i++) {",
      "      if (((l >> i) << i) != l) update(l >> i);",
      "      if (((r >> i) << i) != r) update((r - 1) >> i);",
      "    }",
      "  }",
      "  template <bool (*g)(S)> int max_right(int l) {",
      "    return max_right(l, [](S x) { return g(x); });",
      "  }",
      "  template <class G> int max_right(int l, G g) {",
      "    assert(0 <= l && l <= _n);",
      "    assert(g(e()));",
      "    if (l == _n) return _n;",
      "    l += size;",
      "    for (int i = log; i >= 1; i--) push(l >> i);",
      "    S sm = e();",
      "    do {",
      "      while (l % 2 == 0) l >>= 1;",
      "      if (!g(op(sm, d[l]))) {",
      "        while (l < size) {",
      "          push(l);",
      "          l = (2 * l);",
      "          if (g(op(sm, d[l]))) {",
      "            sm = op(sm, d[l]);",
      "            l++;",
      "          }",
      "        }",
      "        return l - size;",
      "      }",
      "      sm = op(sm, d[l]);",
      "      l++;",
      "    } while ((l & -l) != l);",
      "    return _n;",
      "  }",
      "  template <bool (*g)(S)> int min_left(int r) {",
      "    return min_left(r, [](S x) { return g(x); });",
      "  }",
      "  template <class G> int min_left(int r, G g) {",
      "    assert(0 <= r && r <= _n);",
      "    assert(g(e()));",
      "    if (r == 0) return 0;",
      "    r += size;",
      "    for (int i = log; i >= 1; i--) push((r - 1) >> i);",
      "    S sm = e();",
      "    do {",
      "      r--;",
      "      while (r > 1 && (r % 2)) r >>= 1;",
      "      if (!g(op(d[r], sm))) {",
      "        while (r < size) {",
      "          push(r);",
      "          r = (2 * r + 1);",
      "          if (g(op(d[r], sm))) {",
      "            sm = op(d[r], sm);",
      "            r--;",
      "          }",
      "        }",
      "        return r + 1 - size;",
      "      }",
      "      sm = op(d[r], sm);",
      "    } while ((r & -r) != r);",
      "    return 0;",
      "  }",
      "private:",
      "  int _n, size, log;",
      "  vector<S> d;",
      "  vector<F> lz;",
      "  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }",
      "  void all_apply(int k, F f) {",
      "    d[k] = mapping(f, d[k]);",
      "    if (k < size) lz[k] = composition(f, lz[k]);",
      "  }",
      "  void push(int k) {",
      "    all_apply(2 * k, lz[k]);",
      "    all_apply(2 * k + 1, lz[k]);",
      "    lz[k] = id();",
      "  }",
      "};",
      "",
      "// 区間加算・区間最小値取得",
      "using S = int;",
      "using F = int;",
      "//const S INF = 8e18;",
      "S op(S a, S b){ return min(a, b); }",
      "S e(){ return INF; }",
      "S mapping(F f, S x){ return f+x; }",
      "F composition(F f, F g){ return f+g; }",
      "F id(){ return 0; }",
      "",
      "// 区間加算・区間最大値取得",
      "using S = int;",
      "using F = int;",
      "//const S INF = 8e18;",
      "S op(S a, S b){ return max(a, b); }",
      "S e(){ return -INF; }",
      "S mapping(F f, S x){ return f+x; }",
      "F composition(F f, F g){ return f+g; }",
      "F id(){ return 0; }",
      "",
      "// 区間加算・区間和取得",
      "struct S{",
      "  int val;",
      "  int siz;",
      "};",
      "using F = int;",
      "//const S INF = 8e18;",
      "S op(S a, S b){ return {a.val+b.val, a.siz+b.siz}; }",
      "S e(){ return {0, 0}; }",
      "S mapping(F f, S x){ return {x.val + f*x.siz, x.siz}; }",
      "F composition(F f, F g){ return f+g; }",
      "F id(){ return 0; }",
      "",
      "// 区間変更・区間最小値取得",
      "using S = int;",
      "using F = int;",
      "//const S INF = 8e18;",
      "const F ID = 8e18;",
      "S op(S a, S b){ return min(a, b); }",
      "S e(){ return INF; }",
      "S mapping(F f, S x){ return (f == ID ? x : f); }",
      "F composition(F f, F g){ return (f == ID ? g : f); }",
      "F id(){ return ID; }",
      "",
      "// 区間変更・区間最大値取得",
      "using S = int;",
      "using F = int;",
      "//const S INF = 8e18;",
      "const F ID = 8e18;",
      "S op(S a, S b){ return max(a, b); }",
      "S e(){ return -INF; }",
      "S mapping(F f, S x){ return (f == ID ? x : f); }",
      "F composition(F f, F g){ return (f == ID ? g : f); }",
      "F id(){ return ID; }",
      "",
      "// 区間変更・区間和取得",
      "struct S{",
      "  int val;",
      "  int siz;",
      "};",
      "using F = int;",
      "const F ID = 8e18;",
      "S op(S a, S b){ return {a.val+b.val, a.siz+b.siz}; }",
      "S e(){ return {0, 0}; }",
      "S mapping(F f, S x){",
      "  if(f != ID) x.val = f*x.siz;",
      "  return x;",
      "}",
      "F composition(F f, F g){ return (f == ID ? g : f); }",
      "F id(){ return ID; }",
      "",
      "// 役割",
      "/*",
      "// 区間加算・区間和取得",
      "struct S{",
      "  int val;",
      "  int siz;",
      "};",
      "using F = int;",
      "// 下2つを結合させて上1つを作る操作",
      "S op(S a, S b){ return {a.val+b.val, a.siz+b.siz}; }",
      "// opの単位元",
      "S e(){ return {0, 0}; }",
      "// fをxに作用させる処理",
      "S mapping(F f, S x){ return {x.val + f*x.siz, x.siz}; }",
      "// fをgに追加する処理",
      "F composition(F f, F g){ return f+g; }",
      "// mappingにおける恒等写像",
      "F id(){ return 0; }",
      "*/"
    ],
    "description": "遅延セグ木"
  },
  "LazySegmentTree-use": {
    "prefix": "lazySegTreeUse",
    "body": [
      "// 区間加算・区間最小値取得",
      "vector<S> v(N);",
      "// 区間加算・区間最大値取得",
      "vector<S> v(N);",
      "// 区間加算・区間和取得(サイズあり)",
      "vector<S> v(N, {0, 1});",
      "// 区間変更・区間最小値取得",
      "vector<S> v(N);",
      "// 区間変更・区間最大値取得",
      "vector<S> v(N);",
      "// 区間変更・区間和取得(サイズあり)",
      "vector<S> v(N, {0, 1});",
      "",
      "// 初期値あり(サイズあり)の初期化は以下",
      "// vector<S> A(N); // 最上部の初期化と選ぶ",
      "// rep(i,0,N){",
      "//   int x;",
      "//   cin >> x; // 初期値は問題により全て0だったりする",
      "//   A[i]=S{x,1};",
      "// }",
      "",
      "//lazy_segtree<S, op, e, F, mapping, composition, id> seg(N); // 要素数で初期化(サイズが必要なものは本方法不可)",
      "lazy_segtree<S, op, e, F, mapping, composition, id> seg(v); // 配列で初期化",
      "",
      "int p,x,l,r;",
      "p=1; x=1; l=1; r=3;",
      "seg.apply(l,r,x);        // a[l]...a[r-1]にF(x)を作用",
      "seg.set(p,x);            // a[p]にxを代入(区間最大)",
      "seg.set(p,{x,1});        // a[p]にxを代入(区間加算)",
      "int n1 = seg.get(p).val; // a[p]を取得",
      "int n2 = seg.prod(l,r).val; // op(a[l]...a[r-1])を計算",
      "int n3 = seg.all_prod().val; // op(a[l]...a[n-1])を計算"
    ],
    "description": "セグ木の使い方"
  },
  "SegmentTreeBeats": {
    "prefix": "SGTBeats",
    "body": [
      "template <class T> using vc = vector<T>;",
      "template <class T> class SegmentTreeBeats {",
      "  T inf, zero;",
      "  size_t nn;            // 外から見たサイズ",
      "  size_t length;        // 葉ノードの個数（2べきになるようにパディング）",
      "  vc<T> node_max_first; // ノードに対応する区間の最大値",
      "  vc<T> node_max_second; // ノードに対応する区間の二番目の最大値，区間内が最大値のみのときは -inf",
      "  vc<int> count_max_first; // ノードに対応する区間の最大値の個数",
      "  vc<T> node_min_first;    // ノードに対応する区間の最小値",
      "  vc<T> node_min_second; // ノードに対応する区間の二番目の最小値，区間内が最大値のみのときは inf",
      "  vc<int> count_min_first;     // ノードに対応する区間の最小値の個数",
      "  vc<T> node_sum;              // ノードに対応する区間の総和",
      "  vc<T> lazy_add, lazy_update; // ノードに対応する遅延配列",
      "  vc<pair<int, int>> range;    // ノードに対応する区間の左端・右端（半開区間）",
      "  stack<int> down, up; // クエリを処理するためのスタック．インスタンスを使い回すためにここに置く．",
      "",
      "  // 木のノード k に対する区間 chmin 更新に応じて，区間最大値を更新する（区間和も更新）",
      "  // 区間に含まれる x より大きい要素は，最大値の要素のみである前提",
      "  // 更新前後の差分（負数）を返す",
      "  inline T internal_chmax(const int k, const T x) noexcept {",
      "    T delta = (x - node_max_first[k]) * count_max_first[k];",
      "    node_sum[k] += delta;                       // これから減る分を反映",
      "    if (node_max_first[k] == node_min_first[k]) // 区間内の値が全て同じ値である（つまり x より大きい）とき",
      "      node_max_first[k] = node_min_first[k] = x; // 新しい最大値・最小値が x になる",
      "    else if (node_max_first[k] == node_min_second[k]) // 区間内の値が 2 種類である（大きい方は x より大きい）とき",
      "      node_max_first[k] = node_min_second[k] = x; // 2種類のうち大きい方の値が x になる",
      "    else                                            // 区間内の値が 3 種類以上あるとき",
      "      node_max_first[k] = x;                      // 最大値のみが x になる",
      "    // 必要に応じて，遅延配列にも chmin をかける",
      "    if (lazy_update[k] != inf && x < lazy_update[k]) {",
      "      delta += (x - lazy_update[k]);",
      "      lazy_update[k] = x;",
      "    }",
      "    // assert(lazy_add[k] == zero); // 加算については先に伝播処理が終わっている前提",
      "    return delta;",
      "  }",
      "",
      "  // 木のノード k に対する区間 chmax 更新に応じて，区間最小値を更新する（区間和も更新）",
      "  // 区間に含まれる x 未満の要素は，最小値の要素のみである前提",
      "  inline T internal_chmin(const int k, const T x) noexcept {",
      "    T delta = (x - node_min_first[k]) * count_min_first[k];",
      "    node_sum[k] += delta;                       // これから増える分を反映",
      "    if (node_max_first[k] == node_min_first[k]) // 区間内の値が全て同じ値（つまり x 未満）のとき",
      "      node_max_first[k] = node_min_first[k] = x; // 新しい最大値・最小値が x になる",
      "    else if (node_max_second[k] == node_min_first[k]) // 区間内の値が 2 種類（小さい方は x 未満）のとき",
      "      node_min_first[k] = node_max_second[k] = x; // 2種類のうち小さい方の値が x になる",
      "    else                                            // 区間内の値が 3 種類以上あるとき",
      "      node_min_first[k] = x;                      // 最小値のみが x になる",
      "    // 必要に応じて，遅延配列にも chmax をかける",
      "    if (lazy_update[k] != inf && lazy_update[k] < x) {",
      "      delta += (x - lazy_update[k]);",
      "      lazy_update[k] = x;",
      "    }",
      "    // assert(lazy_add[k] == zero); // 加算については先に伝播処理が終わっている前提",
      "    return delta;",
      "  }",
      "",
      "  // 木のノード k に対する加算処理（と区間和の更新）",
      "  inline void internal_add(const int k, const T x) noexcept {",
      "    node_max_first[k] += x;",
      "    if (node_max_second[k] != -inf) node_max_second[k] += x;",
      "    node_min_first[k] += x;",
      "    if (node_min_second[k] != inf) node_min_second[k] += x;",
      "    node_sum[k] += x * (range[k].second - range[k].first);",
      "    (lazy_update[k] != inf ? lazy_update[k] : lazy_add[k]) += x;",
      "  }",
      "",
      "  // 木のノード k の値の更新（と区間和の更新）",
      "  inline T internal_update(const int k, const T x) noexcept {",
      "    int cnt = (range[k].second - range[k].first);",
      "    T delta = x * cnt - node_sum[k];",
      "    node_max_first[k] = x;",
      "    node_max_second[k] = -inf;",
      "    node_min_first[k] = x;",
      "    node_min_second[k] = inf;",
      "    count_max_first[k] = count_min_first[k] = cnt;",
      "    node_sum[k] = x * cnt;",
      "    lazy_update[k] = x;",
      "    lazy_add[k] = zero;",
      "    return delta;",
      "  }",
      "",
      "  // 木のノード k に関して，子ノードへの伝播処理を行う",
      "  inline void propagate(const int k) noexcept {",
      "    if ((int)length - 1 <= k) return;",
      "    if (lazy_update[k] != inf) {",
      "      internal_update((k << 1) | 0, lazy_update[k]);",
      "      internal_update((k << 1) | 1, lazy_update[k]);",
      "      lazy_update[k] = inf;",
      "      return;",
      "    }",
      "    if (lazy_add[k] != zero) {",
      "      internal_add((k << 1) | 0, lazy_add[k]);",
      "      internal_add((k << 1) | 1, lazy_add[k]);",
      "      lazy_add[k] = zero;",
      "    }",
      "    if (node_max_first[k] < node_max_first[(k << 1) | 0]) {",
      "      internal_chmax((k << 1) | 0, node_max_first[k]);",
      "    }",
      "    if (node_min_first[(k << 1) | 0] < node_min_first[k]) {",
      "      internal_chmin((k << 1) | 0, node_min_first[k]);",
      "    }",
      "    if (node_max_first[k] < node_max_first[(k << 1) | 1]) {",
      "      internal_chmax((k << 1) | 1, node_max_first[k]);",
      "    }",
      "    if (node_min_first[(k << 1) | 1] < node_min_first[k]) {",
      "      internal_chmin((k << 1) | 1, node_min_first[k]);",
      "    }",
      "  }",
      "",
      "  // ノード k について，子ノードの情報をマージする",
      "  inline void merge(const int k) noexcept {",
      "    // 和の更新",
      "    node_sum[k] = node_sum[(k << 1) | 0] + node_sum[(k << 1) | 1];",
      "",
      "    // 最大値の更新",
      "    if (node_max_first[(k << 1) | 0] < node_max_first[(k << 1) | 1]) {",
      "      // 右側の方が大きい",
      "      node_max_first[k] = node_max_first[(k << 1) | 1];",
      "      count_max_first[k] = count_max_first[(k << 1) | 1];",
      "      node_max_second[k] = max(node_max_first[(k << 1) | 0], node_max_second[(k << 1) | 1]);",
      "    } else if (node_max_first[(k << 1) | 0] > node_max_first[(k << 1) | 1]) {",
      "      // 左側の方が大きい",
      "      node_max_first[k] = node_max_first[(k << 1) | 0];",
      "      count_max_first[k] = count_max_first[(k << 1) | 0];",
      "      node_max_second[k] = max(node_max_second[(k << 1) | 0], node_max_first[(k << 1) | 1]);",
      "    } else {",
      "      // 大きさが同じ",
      "      node_max_first[k] = node_max_first[(k << 1) | 0];",
      "      count_max_first[k] = count_max_first[(k << 1) | 0] + count_max_first[(k << 1) | 1];",
      "      node_max_second[k] = max(node_max_second[(k << 1) | 0], node_max_second[(k << 1) | 1]);",
      "    }",
      "",
      "    // 最小値の更新",
      "    if (node_min_first[(k << 1) | 0] < node_min_first[(k << 1) | 1]) {",
      "      // 左側の方が小さい",
      "      node_min_first[k] = node_min_first[(k << 1) | 0];",
      "      count_min_first[k] = count_min_first[(k << 1) | 0];",
      "      node_min_second[k] = min(node_min_second[(k << 1) | 0], node_min_first[(k << 1) | 1]);",
      "    } else if (node_min_first[(k << 1) | 0] > node_min_first[(k << 1) | 1]) {",
      "      // 右側の方が小さい",
      "      node_min_first[k] = node_min_first[(k << 1) | 1];",
      "      count_min_first[k] = count_min_first[(k << 1) | 1];",
      "      node_min_second[k] = min(node_min_first[(k << 1) | 0], node_min_second[(k << 1) | 1]);",
      "    } else {",
      "      // 小ささが同じ",
      "      node_min_first[k] = node_min_first[(k << 1) | 0];",
      "      count_min_first[k] = count_min_first[(k << 1) | 0] + count_min_first[(k << 1) | 1];",
      "      node_min_second[k] = min(node_min_second[(k << 1) | 0], node_min_second[(k << 1) | 1]);",
      "    }",
      "  }",
      "",
      "  // up スタックに記録された木のノードに順番にマージ処理をかける",
      "  // up スタックからは木の葉側から順にノードが取り出される前提",
      "  inline void up_merge() noexcept {",
      "    while (!up.empty()) {",
      "      merge(up.top());",
      "      up.pop();",
      "    }",
      "  }",
      "",
      "  // 木のノード k に伝播処理をかけて，子ノードを処理対象に追加する",
      "  // 伝播が必要な場合のみ呼ばれるので，子ノードは必ず存在する前提",
      "  inline void down_propagate(const int k) noexcept {",
      "    propagate(k);",
      "    down.push((k << 1) | 0);",
      "    down.push((k << 1) | 1);",
      "  }",
      "",
      "  public:",
      "    // コンストラクタ",
      "    SegmentTreeBeats(const int n_, const T inf = INF, const T zero = 0) noexcept : inf(inf), zero(zero) { init(n_); }",
      "    // コンストラクタ",
      "    SegmentTreeBeats(const vector<T> &a, const T inf = INF, const T zero = 0) noexcept : inf(inf), zero(zero) {",
      "      build(a);",
      "    }",
      "",
      "    // 指定要素数で初期化",
      "    void init(const size_t n_) noexcept {",
      "      nn = n_;",
      "      length = 1;",
      "      while (length <= n_) length <<= 1;",
      "",
      "      node_max_first.resize(2 * length);",
      "      node_max_second.resize(2 * length);",
      "      count_max_first.resize(2 * length);",
      "",
      "      node_min_first.resize(2 * length);",
      "      node_min_second.resize(2 * length);",
      "      count_min_first.resize(2 * length);",
      "",
      "      node_sum.assign(2 * length, zero);",
      "      lazy_add.assign(2 * length, zero);",
      "      lazy_update.resize(2 * length, inf);",
      "",
      "      range.resize(2 * length);",
      "      rep(i, 0, length) range[i + length] = {i, i + 1};",
      "      rrep(i, length - 1, 0) range[i] = {range[(i << 1) + 0].first, range[(i << 1) + 1].second};",
      "",
      "      // 実際に要素がある区間",
      "      rep(i, 0, n_) {",
      "        node_max_first[length + i] = node_min_first[length + i] = zero;",
      "        node_max_second[length + i] = -inf;",
      "        node_min_second[length + i] = inf;",
      "        count_max_first[length + i] = count_min_first[length + i] = 1;",
      "      }",
      "      // 2冪にするためにパディングした区間",
      "      rep(i, n_, length) {",
      "        node_max_first[length + i] = node_max_second[length + i] = -inf;",
      "        node_min_first[length + i] = node_min_second[length + i] = inf;",
      "        count_max_first[length + i] = count_min_first[length + i] = 0;",
      "      }",
      "      // 上へ順にマージ",
      "      rrep(i, length - 1, 1) merge(i);",
      "    }",
      "",
      "    // 指定ベクトルで初期化",
      "    void build(const vector<T> &a) noexcept {",
      "      init(a.size());",
      "",
      "      // 実際に要素がある区間だけ更新",
      "      rep(i, 0, nn) node_max_first[length + i] = node_min_first[length + i] = node_sum[length + i] = a[i];",
      "      // 上へ順にマージ",
      "      rrep(i, length - 1, 1) merge(i);",
      "    }",
      "",
      "    // 区間 chmin，半開区間",
      "    // x より大きい要素を x に置き換える",
      "    inline T range_chmin(const int a, const int b, const T x) noexcept {",
      "      T delta = zero;",
      "      down.push(1);",
      "      while (!down.empty()) {",
      "        int k = down.top();",
      "        down.pop();",
      "        // 区間が被っていないか，更新が不要な場合（x 以下の値しか区間に含まれない場合）は飛ばす",
      "        if (b <= range[k].first || range[k].second <= a || node_max_first[k] <= x) continue;",
      "        if (a <= range[k].first && range[k].second <= b && node_max_second[k] < x) {",
      "          // ノード k の区間がクエリ区間に内包されていて，最大値以外は x よりも小さい場合",
      "          delta += internal_chmax(k, x);",
      "        } else {",
      "          // 区間をさらに分割して処理する必要がある場合",
      "          down_propagate(k);",
      "          up.push(k);",
      "        }",
      "      }",
      "      up_merge();",
      "      return delta;",
      "    }",
      "",
      "    // 区間 chmax，半開区間",
      "    // x 未満の要素を x に置き換える",
      "    inline T range_chmax(const int a, const int b, const T x) noexcept {",
      "      T delta = zero;",
      "      down.push(1);",
      "      while (!down.empty()) {",
      "        int k = down.top();",
      "        down.pop();",
      "        // 区間が被っていないか，更新が不要な場合（x 以上の値しか区間に含まれない場合）は飛ばす",
      "        if (b <= range[k].first || range[k].second <= a || x <= node_min_first[k]) continue;",
      "        if (a <= range[k].first && range[k].second <= b && x < node_min_second[k]) {",
      "          // ノード k の区間がクエリ区間に内包されていて，最小値以外は x よりも大きい場合",
      "          delta += internal_chmin(k, x);",
      "        } else {",
      "          // 区間をさらに分割して処理する必要がある場合",
      "          down_propagate(k);",
      "          up.push(k);",
      "        }",
      "      }",
      "      up_merge();",
      "      return delta;",
      "    }",
      "",
      "    // 区間 add，半開区間",
      "    inline void range_add(const int a, const int b, const T x) noexcept {",
      "      down.push(1);",
      "      while (!down.empty()) {",
      "        int k = down.top();",
      "        down.pop();",
      "        // 区間が被っていない場合は飛ばす",
      "        if (b <= range[k].first || range[k].second <= a) continue;",
      "        if (a <= range[k].first && range[k].second <= b) {",
      "          // ノード k の区間がクエリ区間に内包されている場合",
      "          internal_add(k, x);",
      "        } else {",
      "          // 区間をさらに分割して処理する必要がある場合",
      "          down_propagate(k);",
      "          up.push(k);",
      "        }",
      "      }",
      "      up_merge();",
      "    }",
      "",
      "    // 区間 update，半開区間",
      "    inline void range_update(const int a, const int b, const T x) noexcept {",
      "      T delta = zero;",
      "      down.push(1);",
      "      while (!down.empty()) {",
      "        int k = down.top();",
      "        down.pop();",
      "        // 区間が被っていない場合は飛ばす",
      "        if (b <= range[k].first || range[k].second <= a) continue;",
      "        if (a <= range[k].first && range[k].second <= b) {",
      "          // ノード k の区間がクエリ区間に内包されている場合",
      "          delta += internal_update(k, x);",
      "        } else {",
      "          // 区間をさらに分割して処理する必要がある場合",
      "          down_propagate(k);",
      "          up.push(k);",
      "        }",
      "      }",
      "      up_merge();",
      "      return delta;",
      "    }",
      "",
      "    // 区間最大値取得，半開区間",
      "    inline T get_max(const int a, const int b) noexcept {",
      "      down.push(1);",
      "      T v = -inf;",
      "      while (!down.empty()) {",
      "        int k = down.top();",
      "        down.pop();",
      "        // 区間が被っていない場合は飛ばす",
      "        if (b <= range[k].first || range[k].second <= a) continue;",
      "        if (a <= range[k].first && range[k].second <= b) {",
      "          // ノード k の区間がクエリ区間に内包されている場合",
      "          v = max(v, node_max_first[k]);",
      "        } else {",
      "          // 区間をさらに分割して処理する必要がある場合",
      "          down_propagate(k);",
      "        }",
      "      }",
      "      return v;",
      "    }",
      "",
      "    // 区間最小値取得，半開区間",
      "    inline T get_min(const int a, const int b) noexcept {",
      "      down.push(1);",
      "      T v = inf;",
      "      while (!down.empty()) {",
      "        int k = down.top();",
      "        down.pop();",
      "        // 区間が被っていない場合は飛ばす",
      "        if (b <= range[k].first || range[k].second <= a) continue;",
      "        if (a <= range[k].first && range[k].second <= b) {",
      "          // ノード k の区間がクエリ区間に内包されている場合",
      "          v = min(v, node_min_first[k]);",
      "        } else {",
      "          // 区間をさらに分割して処理する必要がある場合",
      "          down_propagate(k);",
      "        }",
      "      }",
      "      return v;",
      "    }",
      "",
      "    // 区間和取得，半開区間",
      "    inline T get_sum(const int a, const int b) noexcept {",
      "      down.push(1);",
      "      T v = zero;",
      "      while (!down.empty()) {",
      "        int k = down.top();",
      "        down.pop();",
      "        // 区間が被っていない場合は飛ばす",
      "        if (b <= range[k].first || range[k].second <= a) continue;",
      "        if (a <= range[k].first && range[k].second <= b) {",
      "          // ノード k の区間がクエリ区間に内包されている場合",
      "          v += node_sum[k];",
      "        } else {",
      "          // 区間をさらに分割して処理する必要がある場合",
      "          down_propagate(k);",
      "        }",
      "      }",
      "      return v;",
      "    }",
      "};"
    ],
    "description": "SGTBeats"
  },
  "SegmentTreeBeats-Use": {
    "prefix": "SGTBeatsUse",
    "body": [
      "// 初期化",
      "vi A={1,2,3,4,5};",
      "SegmentTreeBeats<int> seg(A); // vectorで初期化",
      "SegmentTreeBeats<int> seg(5); // 初期化 要素0-4の5つ確保できる",
      "// 更新",
      "range_chmin(l,r,x);  // [l,r)をxにchmin",
      "range_chmax(l,r,x);  // [l,r)をxにchmax",
      "range_add(l,r,x);    // [l,r)にxを加算",
      "range_update(l,r,x); // [l,r)をxに置き換え",
      "// 取得",
      "int ans=get_max(l,r); // [l,r)の最大",
      "int ans=get_min(l,r); // [l,r)の最小",
      "int ans=get_sum(l,r); // [l,r)の合計"
    ],
    "description": "SGTBeatsの使い方"
  },

// "BIT"==================================================
// "prefix": "BIT",
// "description": "BIT"
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};
    
// "BIT-use"==================================================
// "prefix": "BITUse",
// "description": "BITの使い方"
BIT<int> b(4); // 初期化 要素0-3の4つ確保できる
//b.add(1,3); // 要素1に3を加える
//b.sum(1); // [0,1]の区間和を求める
//b.sum(1,3); // [1,3)の区間和を求める これだけ開区間

  "topoSort": {
    "prefix": "topoSort",
    "body": [
// トポロジカルソート(結果のvectorを返す、閉路を含む場合は要素-1の1つのみを含むvectorを返す)
vi topoSort(vvi &G){
  int N=sz(G); // 頂点数
  // 多重辺を消す
  set<P> s;
  rep(v,0,N){
    fore(to,G[v]){
      s.insert(P(v,to)); // 元->先のペア
    }
  }

  // 自己ループを消す
  rep(i,0,N) s.erase(P(i,i));

  // 多重辺をなくした隣接グラフG2を作る
  // 同時に入次数もカウント
  vvi G2(N);
  vi d(N,0); // 入次数
  fore(e,s){
    int a,b;
    tie(a,b)=e;
    G2[a].emplace_back(b);
    d[b]++;
  }

  min_priority_queue<int> q; // 出力を昇順にする場合
  //queue<int> q; // 出力を処理順にする場合
  rep(i,0,N){
    if(d[i]==0) q.push(i);
  }

  vi ans;
  while(!q.empty()){
    int v=q.top(); q.pop();
    ans.emplace_back(v);
    fore(e,G2[v]){
      d[e]--;
      if(d[e]==0) q.push(e); // 入次数が0になったら使えるようになる
    }
  }
  
  if(sz(ans)==N){
    return ans;
  }else{
    vi res={-1};
    return res;
  }
}
    ],
    "description": "トポロジカルソート"
  },
  "split_str": {
    "prefix": "split_str",
    "body": [
      "// Sをcを区切り文字として分割する関数",
      "//string S; // 改行までを1つの文字列として受け取る方法",
      "//getline(cin,S);",
      "//vector<string> A=split_str(S,' '); // 使い方",
      "vector<string> split_str(string &S,char c){",
      "  vector<string> res;",
      "  stringstream SS(S);",
      "  string S_elem;",
      "  while(getline(SS,S_elem,c)){",
      "    res.emplace_back(S_elem);",
      "  }",
      "  return res;",
      "}"
    ],
    "description": "文字列分割"
  },
// "Mo's algorithm"==================================================
// "prefix": "Mo's_algorithm",
// "description": "Mo's algorithm"
// insert→solveでansに全クエリに対する結果が格納
// add,del を変更していろいろなクエリに対応する
// 以下は区間内の数の種類数についてのクエリが飛んでくる場合

//現在の状態および値
const int MAX_VAL = 100005;
int A[MAX_VAL];   //要素
int cnt[MAX_VAL]; //区間内のiの個数
int res;          //区間内の種類の数

class Mo{
private:
  vector<int> left, right;
  const int width;
  void add(const int id);
  void del(const int id);

public:
  vector<int> ans;

  Mo(const int n) : width((int)sqrt(n)){}
  //クエリ[l,r)
  void insert(const int l, const int r){
    left.emplace_back(l), right.emplace_back(r);
  }
  void solve(){
    const int siz=sz(left);
    int nl=0,nr=0;
    vi ord(siz);
    iota(all(ord),0);
    sort(all(ord),[&](const int a, const int b){
      const int c = left[a] / width, d = left[b] / width;
      return (c==d) ? ((c&1) ? (right[b]<right[a]):(right[a]<right[b])) : (c<d);
    });
    ans.resize(siz);
    for(const int id : ord){
      while(nl>left[id]) add(--nl);
      while(nr<right[id]) add(nr++);
      while(nl<left[id]) del(nl++);
      while(nr>right[id]) del(--nr);
      ans[id] = res;
    }
  }
};

//idは元の配列のインデックス
void Mo::add(const int id){
  // 種類数を求める
  //++cnt[a[id]];
  //if(cnt[a[id]] == 1) ++res;
  // ペア数を求める(ABC242G)
  res-=cnt[A[id]]/2; // 今のペア数を引いて
  cnt[A[id]]+=1;
  res+=cnt[A[id]]/2; // 新しいペア数を足す
}

void Mo::del(const int id){
  // 種類数を求める
  //--cnt[a[id]];
  //if(cnt[a[id]] == 0) --res;
  // ペア数を求める(ABC242G)
  res-=cnt[A[id]]/2; // 今のペア数を引いて
  cnt[A[id]]-=1;
  res+=cnt[A[id]]/2; // 新しいペア数を足す
}

// "Mo's algorithm-Use"==================================================
// "prefix": "Mo's algorithm-Use",
// "description": "Mo's algorithm-Use"
int N;
cin >> N;
Mo mo(N); // N:データ数

rep(i,0,N) cin >> A[i];

int Q;
cin >> Q;
rep(i,0,Q){
  int l,r;
  cin >> l >> r;
  --l;
  mo.insert(l,r); // クエリを[l,r)で全て格納
}
mo.solve();
//const auto& ans=mo.ans;
//rep(i,0,Q) fo(ans[i]);
rep(i,0,Q) fo(mo.ans[i]);

// "NijigenRuisekiwa"==================================================
// "prefix": "NijigenRuisekiwa",
// "description": "二次元累積和"
struct CumulativeSum2D{
  vvi Ac; // accumulate
  int W,H;
  CumulativeSum2D(vvi &A){
    H = sz(A);
    W = sz(A[0]);
    Ac.resize(H+1,vi(W+1,0));
    rep(i,0,H) rep(j,0,W){
      Ac[i+1][j+1]=Ac[i][j+1]+Ac[i+1][j]-Ac[i][j]+A[i][j];
    }
  }
  int sum(int a,int b,int c,int d){
    return Ac[c][d]-Ac[a][d]-Ac[c][b]+Ac[a][b];
  }
};
// CumulativeSum2D cs(A); // vvi Aを渡して構築(A[x][y]の形式)
// int a =cs.sum(x1,y1,x2,y2); // 半開区間で領域を指定
    
// "SanjigenRuisekiwa"==================================================
// "prefix": "SanjigenRuisekiwa",
// "description": "三次元累積和"
struct CumulativeSum3D{
  vvvi Ac; // accumulate
  int H,W,D;
  CumulativeSum3D(vvvi &A){
    H = sz(A);
    W = sz(A[0]);
    D = sz(A[0][0]);
    Ac.resize(H+1,vvi(W+1,vi(D+1,0)));
    rep(i,0,H) rep(j,0,W) rep(k,0,D){
      Ac[i+1][j+1][k+1]=A[i][j][k];
      Ac[i+1][j+1][k+1]+=Ac[i][j+1][k+1]+Ac[i+1][j][k+1]+Ac[i+1][j+1][k];
      Ac[i+1][j+1][k+1]-=Ac[i+1][j][k]+Ac[i][j+1][k]+Ac[i][j][k+1];
      Ac[i+1][j+1][k+1]+=Ac[i][j][k];
    }
  }
  int sum(int x1,int y1,int z1,int x2,int y2,int z2){
    int res=Ac[x2][y2][z2];
    res-=Ac[x1][y2][z2];
    res-=Ac[x2][y1][z2];
    res-=Ac[x2][y2][z1];
    res+=Ac[x1][y1][z2];
    res+=Ac[x1][y2][z1];
    res+=Ac[x2][y1][z1];
    res-=Ac[x1][y1][z1];
    return res;
  }
};
// CumulativeSum3D cs(A); // vvvi Aを渡して構築(A[x][y][z]の形式)
// int a =cs.sum(x1,y1,z1,x2,y2,z2); // 半開区間で領域を指定

  "LCA": {
    "prefix": "LCA",
    "body": [
      "struct LCA {",
      "  vector<vector<int>> parent;  // parent[k][u]:= u の 2^k 先の親",
      "  vector<int> dist;            // root からの距離",
      "  LCA(const vvi &G, int root = 0) { init(G, root); }",
      "",
      "  // 初期化",
      "  void init(const vvi &G, int root = 0) {",
      "    int V = G.size();",
      "    int K = 1;",
      "    while ((1 << K) < V) K++;",
      "    parent.assign(K, vector<int>(V, -1));",
      "    dist.assign(V, -1);",
      "    dfs(G, root, -1, 0);",
      "    for (int k = 0; k + 1 < K; k++) {",
      "      for (int v = 0; v < V; v++) {",
      "        if (parent[k][v] < 0) {",
      "          parent[k + 1][v] = -1;",
      "        } else {",
      "          parent[k + 1][v] = parent[k][parent[k][v]];",
      "        }",
      "      }",
      "    }",
      "  }",
      "",
      "  // 根からの距離と1つ先の頂点を求める",
      "  void dfs(const vvi &G, int v, int p, int d) {",
      "    parent[0][v] = p;",
      "    dist[v] = d;",
      "    fore(e,G[v]) {",
      "      if (e!=p) dfs(G,e,v,d+1);",
      "    }",
      "  }",
      "",
      "  int query(int u, int v) {",
      "    if (dist[u] < dist[v]) swap(u, v);  // u の方が深いとする",
      "    int K = parent.size();",
      "    // LCA までの距離を同じにする",
      "    for (int k = 0; k < K; k++) {",
      "      if ((dist[u] - dist[v]) >> k & 1) {",
      "        u = parent[k][u];",
      "      }",
      "    }",
      "    // 二分探索で LCA を求める",
      "    if (u == v) return u;",
      "    for (int k = K - 1; k >= 0; k--) {",
      "      if (parent[k][u] != parent[k][v]) {",
      "        u = parent[k][u];",
      "        v = parent[k][v];",
      "      }",
      "    }",
      "    return parent[0][u];",
      "  }",
      "",
      "  // 2頂点間の距離を求める",
      "  int get_dist(int u, int v) { return dist[u] + dist[v] - 2 * dist[query(u, v)]; }",
      "",
      "  // パス上に頂点があるか判定する",
      "  bool is_on_path(int u, int v, int a) { return get_dist(u, a) + get_dist(a, v) == get_dist(u, v); }",
      "};"
    ],
    "description": "最近共通祖先(LCA)"
  },
  "LCA-Use": {
    "prefix": "LCA-Use",
    "body": [
      "LCA lca(G,root); // vvi G(有向でも良いが無向の方が良い),根番号を渡して構築",
      "lca.query(u,v); // 頂点u,vのLCA",
      "lca.get_dist(u,v); // 頂点u,vの距離",
      "lca.is_on_path(u,v); // パス上に頂点があるか判定する"
    ],
    "description": "最近共通祖先(LCA)の使い方"
  },
  "SCC": {
    "prefix": "SCC",
    "body": [
      // https://pione.hatenablog.com/entry/2021/03/11/232159
      // rebuild()の間違い修正済み(N→n),機能追加
      "struct SCC{",
      "  int n;",
      "  vvi G, rG;",
      "  vi order, component;",
      "  vector<bool> used;",
      "  void dfs(int v){",
      "    used[v]=1;",
      "    fore(nv,G[v]){",
      "      if (!used[nv]) dfs(nv);",
      "    }",
      "    order.push_back(v);",
      "  }",
      "  void rdfs(int v, int k) {",
      "    component[v]=k;",
      "    fore(nv,rG[v]){",
      "      if(component[nv]<0) rdfs(nv, k);",
      "    }",
      "  }",
      "",
      "  // コンストラクタ",
      "  SCC(vvi &_G) {",
      "    n = _G.size();",
      "    G = _G;",
      "    rG.resize(n);",
      "    component.assign(n, -1);",
      "    used.resize(n);",
      "    rep(v,0,n) {",
      "      fore(nv,G[v]) rG[nv].push_back(v);",
      "    }",
      "    rep(v,0,n) if(!used[v]) dfs(v);",
      "    int k = 0;",
      "    reverse(all(order));",
      "    fore(v,order) if(component[v]==-1) rdfs(v, k), k++;",
      "  }",
      "",
      "  /// 頂点(u, v)が同じ強連結成分に含まれるか",
      "  bool is_same(int u, int v) {return component[u]==component[v];}",
      "",
      "  /// 強連結成分を1つのノードに潰したグラフを再構築する",
      "  vector<vector<int>> rebuild(){",
      "    int N=*max_element(all(component)) + 1;",
      "    vvi rebuildedG(N);",
      "    set<P> connected;",
      "    rep(v,0,n){",
      "      fore(nv,G[v]){",
      "        if(component[v]!=component[nv] and !connected.count(P(v, nv))) {",
      "          connected.insert(P(v,nv));",
      "          rebuildedG[component[v]].push_back(component[nv]);",
      "        }",
      "      }",
      "    }",
      "    return rebuildedG;",
      "  }",
      "",
      "  // 各SCCにどの頂点が所属するか求める",
      "  vvi get_group(){",
      "    int N=*max_element(all(component)) + 1;",
      "    vvi group(N);",
      "    rep(v,0,n){",
      "      group[component[v]].emplace_back(v);",
      "    }",
      "    return group;",
      "  }",
      "};"
    ],
    "description": "強連結成分分解(SCC)"
  },
  "SCC-Use": {
    "prefix": "SCC-Use",
    "body": [
      "SCC scc(G); // SCCを構築",
      "vi comp=scc.component; // 各頂点がどのSCCに属するかを示す情報",
      "vvi group=scc.get_group(); // 各SCCにどの頂点が所属するか",
      "vvi G2=scc.rebuild(); // 強連結成分を1つのノードに潰したグラフを再構築",
      "// G={{1},{2},{0,3},{4},{3}};",
      "// comp={0,0,0,1,1};",
      "// group={{0,1,2},{3,4}};",
      "// G2={{1},{}};"
    ],
    "description": "強連結成分分解(SCC)の使い方"
  },
  "FordFulkerson": {
    "prefix": "FordFulkerson",
    "body": [
      "struct Edge{",
      "  int to;",
      "  int cap;",
      "  int rev;",
      "};",
      "",
      "struct Ford_Fulkerson{",
      "  vector<vector<Edge>> G;",
      "  vector<bool> used;",
      "  int N;",
      "",
      "  Ford_Fulkerson(vector<vector<P>> G_){",
      "    N = sz(G_);",
      "    G.resize(N);",
      "    used.resize(N, false);",
      "",
      "    rep(from,0,N){",
      "      for(P p : G_[from]){",
      "        ll to = p.first;",
      "        ll cap = p.second;",
      "        G[from].emplace_back((Edge){to, cap, sz(G[to])});",
      "        G[to].emplace_back((Edge){from, 0, sz(G[from])-1});",
      "      }",
      "    }",
      "  }",
      "",
      "  int dfs(int v, int t, int f, vector<vector<Edge>> &H){",
      "    if(v == t) return f;",
      "    used[v] = true;",
      "    rep(i,0,sz(H[v])){",
      "      Edge &e = H[v][i];",
      "      if(!used[e.to] && e.cap > 0){",
      "        int d = dfs(e.to, t, min(f, e.cap), H);",
      "        if(d > 0){",
      "          e.cap -= d;",
      "          H[e.to][e.rev].cap += d;",
      "          return d;",
      "        }",
      "      }",
      "    }",
      "",
      "    return 0;",
      "  }",
      "",
      "  int max_flow(int s, int t){",
      "    int flow = 0;",
      "    vector<vector<Edge>> H(N);",
      "    rep(from,0,N) fore(e,G[from]) H[from].emplace_back(e);",
      "    for(;;){",
      "      rep(i,0,N) used[i] = false;",
      "      int f = dfs(s, t, INF, H);",
      "      if(f == 0) return flow;",
      "      flow += f;",
      "    }",
      "  }",
      "};"
    ],
    "description": "フォード・ファルカーソン法"
  },
  "FordFulkerson-Use": {
    "prefix": "FordFulkerson-Use",
    "body": [
      "// https://qiita.com/drken/items/7f98315b56c95a6181a4",
      "最大マッチング:サイズ|M|",
      "最小点被覆:サイズ|M|",
      "最大安定集合:サイズ|V|-|M|",
      "最小点被覆:サイズ|V|-|M|(孤立点がある場合は解なし)",
      "",
      "vector<vector<P>> G(N+2); // pair<int,int>=(行先,容量)でグラフを構築",
      "Ford_Fulkerson FF(G); // 残余グラフを構築",
      "int ans=FF.max_flow(s,t); // sからtへの最大流を計算"
    ],
    "description": "フォード・ファルカーソン法の使い方"
  },
  "LIS": {
    "prefix": "LIS",
    "body": [
      "int LIS(const vi &a){",
      "  int N = sz(a);",
      "  vi dp(N,INF);",
      "  rep(i,0,N){",
      "    auto it = lower_bound(all(dp),a[i]);",
      "    *it = a[i];",
      "  }",
      "  return lower_bound(all(dp), INF) - dp.begin();",
      "}"
    ],
    "description": "LIS(同じ値は潰れる)"
  },
  "エラトステネスの篩": {
    "prefix": "Eratosthenes",
    "body": [
      "vi Eratosthenes(int mx){",
      "  vi res(mx+1,1);",
      "  res[0]=0;",
      "  res[1]=0;",
      "  for(int i=2; i*i<=mx; ++i){",
      "    if(res[i]==0) continue;",
      "    for(int j=i*2; j<=mx; j+=i){",
      "      res[j]=0;",
      "    }",
      "  }",
      "  return res;",
      "}",
      "",
      "//vi is_prime=Eratosthenes(MX); // 0以上MX以下を判定できる"
    ],
    "description": "エラトステネスの篩"
  },
  "ダイクストラ": {
    "prefix": "Dijkstra",
    "body": [
// グラフと始点を渡すと各頂点への最短距離を返すダイクストラ
struct Edge{
  int to,co;
  Edge(int to=0, int co=0): to(to), co(co) {}
};
vi dijkstra(vector<vector<Edge>> &g, int s){
  vi dist(g.size(), INF);
  min_priority_queue<P> q;
  dist[s] = 0;
  q.emplace(dist[s],s);
  while(!q.empty()){
    int d,cu;
    tie(d,cu)=q.top(); q.pop();
    if(dist[cu] < d) continue;
    fore(e,g[cu]){
      if(chmin(dist[e.to],d+e.co)){
        q.emplace(dist[e.to],e.to);
      }
    }
  }
  return dist;
}
// main関数内で以下のように使う
vector<vector<Edge>> G(N);
rep(i,0,M){
  int u,v,c;
  cin >> u >> v >> c;
  u--; v--;
  G[u].emplace_back(Edge(v,c));
  G[v].emplace_back(Edge(u,c));
}
vi dist=dijkstra(G,0); // 頂点0を始点とする各頂点への距離

    ],
    "description": "ダイクストラ"
  },
  "ダイクストラ(double)": {
    "prefix": "Dijkstra_double",
    "body": [
      "// グラフと始点を渡すと各頂点への最短距離を返すダイクストラ",
      "struct Edge{",
      "  int to;",
      "  double co;",
      "  Edge(int to=0, double co=0): to(to), co(co) {}",
      "};",
      "vector<double> dijkstra(vector<vector<Edge>> &g, int s){",
      "  vector<double> dist(g.size(), INF);",
      "  min_priority_queue<pair<double,int>> q;",
      "  dist[s] = 0;",
      "  q.emplace(dist[s],s);",
      "  while(!q.empty()){",
      "    double d;",
      "    int cu;",
      "    tie(d,cu)=q.top(); q.pop();",
      "    if(dist[cu] < d) continue;",
      "    fore(e,g[cu]){",
      "      if(chmin(dist[e.to],d+e.co)){",
      "        q.emplace(dist[e.to],e.to);",
      "      }",
      "    }",
      "  }",
      "  return dist;",
      "}",
      "// main関数内で以下のように使う",
      "vector<vector<Edge>> G(N);",
      "rep(i,0,M){",
      "  int u,v;",
      "  double c;",
      "  cin >> u >> v >> c;",
      "  u--; v--;",
      "  G[u].emplace_back(Edge(v,c));",
      "  G[v].emplace_back(Edge(u,c));",
      "}",
      "vector<double> dist=dijkstra(G,0); // 頂点0を始点とする各頂点への距離"
    ],
    "description": "ダイクストラ(double)"
  },
  "ダイクストラ(One)": {
    "prefix": "Dijkstra_One",
    "body": [
// グラフと始点を渡すと各頂点への最短距離を返すダイクストラ
vi dijkstra(vvi &g, int s){
  vi dist(g.size(), INF);
  queue<P> q;
  dist[s] = 0;
  q.emplace(dist[s],s);
  while(!q.empty()){
    int d,cu;
    tie(d,cu)=q.front(); q.pop();
    if(dist[cu] < d) continue;
    fore(nx,g[cu]){
      if(chmin(dist[nx],d+1)){
        q.emplace(dist[nx],nx);
      }
    }
  }
  return dist;
}
// main関数内で以下のように使う
vvi G(N);
rep(i,0,M){
  int u,v;
  cin >> u >> v;
  u--; v--;
  G[u].emplace_back(v);
  G[v].emplace_back(u);
}
vi dist=dijkstra(G,0); // 頂点0を始点とする各頂点への距離
    ],
    "description": "ダイクストラ(One)"
  },
  "ダイクストラ(サイクル)": {
    "prefix": "Dijkstra_Cycle",
    "body": [
// グラフと始点を渡すと各頂点への最短距離を返すダイクストラ(始点に戻る)
struct Edge{
  int to,co;
  Edge(int to=0, int co=0): to(to), co(co) {}
};
vi dijkstra(vector<vector<Edge>> &g, int s){
  vi dist(g.size(), INF);
  min_priority_queue<P> q;
  // 最初にスタート地点に繋がる全ての町への距離を求める  
  fore(e,g[s]){
    int d=e.co;
    int nx=e.to;
    if(chmin(dist[nx],d)) q.emplace(dist[nx],nx);
  }
  while(!q.empty()){
    int d,cu;
    tie(d,cu)=q.top(); q.pop();
    if(dist[cu] < d) continue;
    fore(e,g[cu]){
      if(chmin(dist[e.to],d+e.co)){
        q.emplace(dist[e.to],e.to);
      }
    }
  }
  return dist;
}
// main関数内で以下のように使う
vector<vector<Edge>> G(N);
rep(i,0,M){
  int u,v,c;
  cin >> u >> v >> c;
  u--; v--;
  G[u].emplace_back(Edge(v,c));
}
vi dist=dijkstra(G,0); // 頂点0を始点とする各頂点への距離
    ],
    "description": "ダイクストラ(Cycle)"
  },
  
  "ベルマンフォード": {
    "prefix": "Bellman-Ford",
    "body": [
      "// グラフと始点を渡すと各頂点への最短距離を返すベルマンフォード(負閉路を持つ場合は{}を返す)",
      "struct Edge{",
      "  int to,co;",
      "  Edge(int to=0, int co=0): to(to), co(co) {}",
      "};",
      "vi bellman_ford(vector<vector<Edge>> &g, int s){",
      "  bool exist_negative_cycle=false; // 負閉路を持つか",
      "  vi dist(g.size(), INF);",
      "  dist[s] = 0;",
      "  int N=sz(g);",
      "  rep(i,0,N){",
      "    bool update=false; // 更新有無を記録",
      "    rep(v,0,N){",
      "      if(dist[v]==INF) continue;",
      "      fore(e,g[v]){",
      "        if(chmin(dist[e.to],dist[v]+e.co)) update=true;",
      "      }",
      "    }",
      "    if(!update) break; // 更新がなくなったら既に最短経路が求められている",
      "    if(i==N-1 and update) exist_negative_cycle=true; // N回目の反復で更新が行われたならば、負閉路をもつ",
      "  }",
      "  if(exist_negative_cycle) return {};",
      "  return dist;",
      "}",
      "// main関数内で以下のように使う",
      "vector<vector<Edge>> G(N);",
      "rep(i,0,M){",
      "  int u,v,c;",
      "  cin >> u >> v >> c;",
      "  u--; v--;",
      "  G[u].emplace_back(Edge(v,c));",
      "}",
      "vi dist=bellman_ford(G,0); // 頂点0を始点とする各頂点への距離",
    ],
    "description": "ベルマンフォード"
  },
  "dfs根付き木で自分+子の要素数を求める": {
    "prefix": "dfs_get_child_num",
    "body": [
      "// 根付き木で自分+子の要素数を求める",
      "vi dp; // グローバル変数で渡す",
      "void dfs_get_child_num(vvi &G, int cu, int pa=-1){",
      "  dp[cu]=1;",
      "  fore(e,G[cu]){",
      "    if(e==pa) continue;",
      "    dfs_get_child_num(G,e,cu);",
      "    dp[cu]+=dp[e];",
      "  }",
      "}",
      "// main関数で以下のように使う",
      "int N;",
      "cin >> N;",
      "vvi G(N);",
      "rep(i,0,N-1){",
      "  int a,b;",
      "  cin >> a >> b;",
      "  a--; b--;",
      "  G[a].emplace_back(b);",
      "  G[b].emplace_back(a);",
      "}",
      "dp.resize(N,0); // グローバル変数の初期化",
      "dfs_get_child_num(G,0); // 自分以下の要素数を求める"
    ],
    "description": "dfs根付き木で自分+子の要素数を求める"
  },
// "範囲外スキップ"==================================================
// "prefix": "is_outer_range",
// "description": "範囲外スキップ"
bool is_outer_range(int R1,int r1,int R2,int r2){
  return (r1<0 or R1<=r1 or r2<0 or R2<=r2);
}
//if(is_outer_range(H,nx,W,ny)) continue;

// "ダブリング"==================================================
// "prefix": "doubling",
// "description": "ダブリング"
int N;
cin >> N;
vi A(N);
rep(i,0,N) cin >> A[i];

// 上限の変更時\"!!!!!!!!!!\"も変更する
// 32:2^32-1(4,294,967,296-1)回まで
// 42:2^42-1(4,398,046,511,104-1)回まで
// 52:2^52-1(4,503,599,627,370,496-1)回まで
// 62:2^62-1(4,611,686,018,427,387,904-1)回まで
vvi dp(32,vi(N)); // 2^32-1(4,294,967,296-1)回までの移動に対応可能
rep(i,0,N) dp[0][i]=A[i]; // 1ターン後の位置
rep(t,0,31) rep(i,0,N) dp[t+1][i]=dp[t][dp[t][i]]; // 構築 !!!!!!!!!!

// xから開始してnumターン後の位置を求める
int x=5;
int num=10000;
rep(t,0,32){ // !!!!!!!!!!
  if(num>>t&1) x=dp[t][x];
}
fo(x);

  "RollingHash": {
    "prefix": "RollingHash",
    "body": [
      "template< unsigned mod >",
      "struct RollingHash {",
      "  vector< unsigned > hashed, power;",
      "",
      "  inline unsigned mul(unsigned a, unsigned b) const {",
      "    unsigned long long x = (unsigned long long) a * b;",
      "    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;",
      "    asm(\"divl %4; \\n\\t\" : \"=a\" (d), \"=d\" (m) : \"d\" (xh), \"a\" (xl), \"r\" (mod));",
      "    return m;",
      "  }",
      "",
      "  RollingHash(const string &s, unsigned base = 10007) {",
      "    int sz = (int) s.size();",
      "    hashed.assign(sz + 1, 0);",
      "    power.assign(sz + 1, 0);",
      "    power[0] = 1;",
      "    for(int i = 0; i < sz; i++) {",
      "      power[i + 1] = mul(power[i], base);",
      "      hashed[i + 1] = mul(hashed[i], base) + s[i];",
      "      if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;",
      "    }",
      "  }",
      "",
      "  unsigned get(int l, int r) const {",
      "    unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);",
      "    if(ret >= mod) ret -= mod;",
      "    return ret;",
      "  }",
      "",
      "unsigned r_get(int l, int r, int N) const {",
      "  return get(N-r,N-l);",
      "}",
      "",
      "  unsigned connect(unsigned h1, int h2, int h2len) const {",
      "    unsigned ret = mul(h1, power[h2len]) + h2;",
      "    if(ret >= mod) ret -= mod;",
      "    return ret;",
      "  }",
      "",
      "  int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {",
      "    int len = min(r1 - l1, r2 - l2);",
      "    int low = -1, high = len + 1;",
      "    while(high - low > 1) {",
      "      int mid = (low + high) / 2;",
      "      if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;",
      "      else high = mid;",
      "    }",
      "    return (low);",
      "  }",
      "};",
      "",
      "//using RH = RollingHash< 1000000007 >;",
      "using RH = RollingHash< 2147483647 >;"
    ],
    "description": "RollingHash"
  },
  "RollingHash-use": {
    "prefix": "RollingHashUse",
    "body": [
      "RH rh(S); // 文字列Sのハッシュテーブルを構築",
      "//int a=rh.get(l,r); // [l,r)のハッシュ値を求める",
      "//int b=rh.connect(h1,h2,h2len); // ハッシュ値h1と長さh2lenのハッシュ値h2を結合する",
      "//rh.LCP(b,l1,r1,l2,r2); // 区間[l1,r1)とハッシュテーブルbからなる区間[l2,r2)の文字列の最長共通接頭辞の長さを求める",
      "// 反転後のものに作用させる,反転前の区間を与えるとその区間を反転させたハッシュを返す",
      "// abcdeの反転後のedcbaのハッシュをrh_revとする rh_rev.r_get(0,3,5)はcbaのハッシュを返す",
      "//int H2=rh_rev.r_get(l,r,len);",
      "//ABC284F"
    ],
    "description": "RollingHashの使用例"
  },
  "ImplicitTreap": {
    "prefix": "ImplicitTreap",
    "body": [
      "// T0: 元の配列のモノイド",
      "// T1: T0に対する作用素モノイド",
      "template <class T0, class T1>",
      "class BaseImplicitTreap {",
      "  // T0上の演算、単位元",
      "  virtual T0 f0(T0, T0) = 0;",
      "  const T0 u0;",
      "  // T1上の演算、単位元",
      "  virtual T1 f1(T1, T1) = 0;",
      "  const T1 u1;",
      "  // T0に対するT1の作用",
      "  virtual T0 g(T0, T1) = 0;",
      "  // 多数のt1(T1)に対するf1の合成",
      "  virtual T1 p(T1, int) = 0;",
      "",
      "  class xorshift {",
      "    uint64_t x;",
      "",
      "  public:",
      "    xorshift() {",
      "      mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());",
      "      x = rnd();",
      "      for (int i = 0; i < 100; i++) {",
      "        random();",
      "      }",
      "    }",
      "",
      "    uint64_t random() {",
      "      x = x ^ (x << 7);",
      "      return x = x ^ (x >> 9);",
      "    }",
      "  } rnd;",
      "",
      "  struct Node {",
      "    T0 value, acc;",
      "    T1 lazy;",
      "    int priority, cnt;",
      "    bool rev;",
      "    Node *l, *r;",
      "",
      "    Node(T0 value_, int priority_, T0 u0_, T1 u1_)",
      "      : value(value_), acc(u0_), lazy(u1_), priority(priority_), cnt(1), rev(false), l(nullptr), r(nullptr) {}",
      "  } *root = nullptr;",
      "",
      "  using Tree = Node *;",
      "",
      "  int cnt(Tree t) { return t ? t->cnt : 0; }",
      "",
      "  T0 acc(Tree t) { return t ? t->acc : u0; }",
      "",
      "  void update_cnt(Tree t) {",
      "    if (t) {",
      "      t->cnt = 1 + cnt(t->l) + cnt(t->r);",
      "    }",
      "  }",
      "",
      "  void update_acc(Tree t) {",
      "    if (t) {",
      "      t->acc = f0(acc(t->l), f0(t->value, acc(t->r)));",
      "    }",
      "  }",
      "",
      "  void pushup(Tree t) { update_cnt(t), update_acc(t); }",
      "",
      "  void pushdown(Tree t) {",
      "    if (t && t->rev) {",
      "      t->rev = false;",
      "      swap(t->l, t->r);",
      "      if (t->l) t->l->rev ^= 1;",
      "      if (t->r) t->r->rev ^= 1;",
      "    }",
      "    if (t && t->lazy != u1) {",
      "      if (t->l) {",
      "        t->l->lazy = f1(t->l->lazy, t->lazy);",
      "        t->l->acc = g(t->l->acc, p(t->lazy, cnt(t->l)));",
      "      }",
      "      if (t->r) {",
      "        t->r->lazy = f1(t->r->lazy, t->lazy);",
      "        t->r->acc = g(t->r->acc, p(t->lazy, cnt(t->r)));",
      "      }",
      "      t->value = g(t->value, p(t->lazy, 1));",
      "      t->lazy = u1;",
      "    }",
      "    pushup(t);",
      "  }",
      "",
      "  void split(Tree t, int key, Tree &l, Tree &r) {",
      "    if (!t) {",
      "      l = r = nullptr;",
      "      return;",
      "    }",
      "    pushdown(t);",
      "    int implicit_key = cnt(t->l) + 1;",
      "    if (key < implicit_key) {",
      "      split(t->l, key, l, t->l), r = t;",
      "    } else {",
      "      split(t->r, key - implicit_key, t->r, r), l = t;",
      "    }",
      "    pushup(t);",
      "  }",
      "",
      "  void insert(Tree &t, int key, Tree item) {",
      "    Tree t1, t2;",
      "    split(t, key, t1, t2);",
      "    merge(t1, t1, item);",
      "    merge(t, t1, t2);",
      "  }",
      "",
      "  void merge(Tree &t, Tree l, Tree r) {",
      "    pushdown(l);",
      "    pushdown(r);",
      "    if (!l || !r) {",
      "      t = l ? l : r;",
      "    } else if (l->priority > r->priority) {",
      "      merge(l->r, l->r, r), t = l;",
      "    } else {",
      "      merge(r->l, l, r->l), t = r;",
      "    }",
      "    pushup(t);",
      "  }",
      "",
      "  void erase(Tree &t, int key) {",
      "    Tree t1, t2, t3;",
      "    split(t, key + 1, t1, t2);",
      "    split(t1, key, t1, t3);",
      "    merge(t, t1, t2);",
      "  }",
      "",
      "  void update(Tree t, int l, int r, T1 x) {",
      "    if (l >= r) return;",
      "    Tree t1, t2, t3;",
      "    split(t, l, t1, t2);",
      "    split(t2, r - l, t2, t3);",
      "    t2->lazy = f1(t2->lazy, x);",
      "    t2->acc = g(t2->acc, p(x, cnt(t2)));",
      "    merge(t2, t2, t3);",
      "    merge(t, t1, t2);",
      "  }",
      "",
      "  T0 query(Tree t, int l, int r) {",
      "    if (l == r) return u0;",
      "    Tree t1, t2, t3;",
      "    split(t, l, t1, t2);",
      "    split(t2, r - l, t2, t3);",
      "    T0 ret = t2->acc;",
      "    merge(t2, t2, t3);",
      "    merge(t, t1, t2);",
      "    return ret;",
      "  }",
      "",
      "  // [l, r)の中で左から何番目か",
      "  int find(Tree t, T0 x, int offset, bool left = true) {",
      "    if (f0(t->acc, x) == x) {",
      "      return -1;",
      "    } else {",
      "      if (left) {",
      "        if (t->l && f0(t->l->acc, x) != x) {",
      "          return find(t->l, x, offset, left);",
      "        } else {",
      "          return (f0(t->value, x) != x) ? offset + cnt(t->l) : find(t->r, x, offset + cnt(t->l) + 1, left);",
      "        }",
      "      } else {",
      "        if (t->r && f0(t->r->acc, x) != x) {",
      "          return find(t->r, x, offset + cnt(t->l) + 1, left);",
      "        } else {",
      "          return (f0(t->value, x) != x) ? offset + cnt(t->l) : find(t->l, x, offset, left);",
      "        }",
      "      }",
      "    }",
      "  }",
      "",
      "  void reverse(Tree t, int l, int r) {",
      "    if (l > r) return;",
      "    Tree t1, t2, t3;",
      "    split(t, l, t1, t2);",
      "    split(t2, r - l, t2, t3);",
      "    t2->rev ^= 1;",
      "    merge(t2, t2, t3);",
      "    merge(t, t1, t2);",
      "  }",
      "",
      "  // [l, r)の先頭がmになるようにシフトさせる。std::rotateと同じ仕様",
      "  void rotate(Tree t, int l, int m, int r) {",
      "    reverse(t, l, r);",
      "    reverse(t, l, l + r - m);",
      "    reverse(t, l + r - m, r);",
      "  }",
      "",
      "  void dump(Tree t) {",
      "    if (!t) return;",
      "    pushdown(t);",
      "    dump(t->l);",
      "    cout << t->value << \" \";",
      "    dump(t->r);",
      "  }",
      "",
      "public:",
      "  BaseImplicitTreap(T0 u0_, T1 u1_) : u0(u0_), u1(u1_) {}",
      "",
      "  void set_by_vector(const vector<T0> &a) {",
      "    for (int i = 0; i < a.size(); i++) {",
      "      insert(i, a[i]);",
      "    }",
      "  }",
      "",
      "  int size() { return cnt(root); }",
      "",
      "  void insert(int pos, T0 x) { insert(root, pos, new Node(x, rnd.random(), u0, u1)); }",
      "",
      "  void update(int l, int r, T1 x) { update(root, l, r, x); }",
      "",
      "  T0 query(int l, int r) { return query(root, l, r); }",
      "",
      "  // 二分探索。[l, r)内のkでf0(tr[k], x) != xとなる最左/最右のもの。存在しない場合は-1",
      "  // たとえばMinMonoidの場合、x未満の最左/最右の要素の位置を返す",
      "  int binary_search(int l, int r, T0 x, bool left = true) {",
      "    if (l >= r) return -1;",
      "    Tree t1, t2, t3;",
      "    split(root, l, t1, t2);",
      "    split(t2, r - l, t2, t3);",
      "    int ret = find(t2, x, l, left);",
      "    merge(t2, t2, t3);",
      "    merge(root, t1, t2);",
      "    return ret;",
      "  }",
      "",
      "  void erase(int pos) { erase(root, pos); }",
      "",
      "  void reverse(int l, int r) { reverse(root, l, r); }",
      "",
      "  void rotate(int l, int m, int r) { rotate(root, l, m, r); }",
      "",
      "  void dump() {",
      "    dump(root);",
      "    cout << endl;",
      "  }",
      "",
      "  T0 operator[](int pos) { return query(pos, pos + 1); }",
      "};",
      "",
      "template <class T0, class T1>",
      "struct MinUpdateQuery : public BaseImplicitTreap<T0, T1> {",
      "  using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;",
      "  MinUpdateQuery() : MinUpdateQuery(numeric_limits<T0>::max(), numeric_limits<T1>::min()) {}",
      "  T0 f0(T0 x, T0 y) override { return min(x, y); }",
      "  T1 f1(T1 x, T1 y) override { return y == numeric_limits<T1>::min() ? x : y; }",
      "  T0 g(T0 x, T1 y) override { return y == numeric_limits<T1>::min() ? x : y; }",
      "  T1 p(T1 x, int len) override { return x; }",
      "};",
      "",
      "template <class T0, class T1>",
      "struct SumAddQuery : public BaseImplicitTreap<T0, T1> {",
      "  using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;",
      "  SumAddQuery() : SumAddQuery(0, 0) {}",
      "  T0 f0(T0 x, T0 y) override { return x + y; }",
      "  T1 f1(T1 x, T1 y) override { return x + y; }",
      "  T0 g(T0 x, T1 y) override { return x + y; }",
      "  T1 p(T1 x, int len) override { return x * len; }",
      "};",
      "",
      "template <class T0, class T1>",
      "struct MinAddQuery : public BaseImplicitTreap<T0, T1> {",
      "  using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;",
      "  MinAddQuery() : MinAddQuery(numeric_limits<T0>::max(), 0) {}",
      "  T0 f0(T0 x, T0 y) override { return min(x, y); }",
      "  T1 f1(T1 x, T1 y) override { return x + y; }",
      "  T0 g(T0 x, T1 y) override { return x + y; }",
      "  T1 p(T1 x, int len) override { return x; }",
      "};",
      "",
      "template <class T0, class T1>",
      "struct SumUpdateQuery : public BaseImplicitTreap<T0, T1> {",
      "  using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;",
      "  SumUpdateQuery() : SumUpdateQuery(0, numeric_limits<T1>::min()) {}",
      "  T0 f0(T0 x, T0 y) override { return x + y; }",
      "  T1 f1(T1 x, T1 y) override { return y == numeric_limits<T1>::min() ? x : y; }",
      "  T0 g(T0 x, T1 y) override { return y == numeric_limits<T1>::min() ? x : y; }",
      "  T1 p(T1 x, int len) override { return x == numeric_limits<T1>::min() ? numeric_limits<T1>::min() : x * len; }",
      "};",
      "",
      "template <class T0>",
      "struct SumAffineQuery : public BaseImplicitTreap<T0, pair<T0, T0>> {",
      "  using T1 = pair<T0, T0>;  // first * x + second",
      "  using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;",
      "  SumAffineQuery() : SumAffineQuery(0, {1, 0}) {}",
      "  T0 f0(T0 x, T0 y) override { return x + y; }",
      "  T1 f1(T1 x, T1 y) override { return {x.first * y.first, x.second * y.first + y.second}; }",
      "  T0 g(T0 x, T1 y) override { return y.first * x + y.second; }",
      "  T1 p(T1 x, int len) override { return {x.first, x.second * len}; }",
      "  // update(i, j, {a, b}); // [i, j)にax + bを作用",
      "  // update(i, j, {0, a}); // update",
      "  // update(i, j, {1, a}); // 加算",
      "  // update(i, j, {a, 0}); // 倍",
      "};",
      "",
      "template <class T>",
      "struct MinmaxAffineQuery : public BaseImplicitTreap<pair<T, T>, pair<T, T>> {",
      "  using T0 = pair<T, T>;  // {min, max}",
      "  using T1 = pair<T, T>;  // first * x + second",
      "  using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;",
      "  MinmaxAffineQuery()",
      "    : MinmaxAffineQuery({numeric_limits<T>::max(), -numeric_limits<T>::max()}, {1, 0}) {",
      "  }  // TODO: _u1を使うとコンパイル通らない原因不明",
      "  T0 f0(T0 x, T0 y) override { return {min(x.first, y.first), max(x.second, y.second)}; }",
      "  T1 f1(T1 x, T1 y) override { return {x.first * y.first, x.second * y.first + y.second}; }",
      "  T0 g(T0 x, T1 y) override {",
      "    T0 ret = {x.first * y.first + y.second, x.second * y.first + y.second};",
      "    if (y.first < 0) swap(ret.first, ret.second);",
      "    return ret;",
      "  }",
      "  T1 p(T1 x, int len) override { return x; }",
      "  // update(i, j, {a, b}); // [i, j)にax + bを作用",
      "  // update(i, j, {0, a}); // update",
      "  // update(i, j, {1, a}); // 加算",
      "  // update(i, j, {a, 0}); // 倍",
      "};"
    ],
    "description": "ImplicitTreap"
  },

// "Ruisekiwa"==================================================
// "prefix": "Ruisekiwa",
// "description": "累積和"
vi ruisekiwa(vi &A){
  int N=sz(A);
  vi res(N+1,0);
  rep(i,0,N) res[i+1]=res[i]+A[i];
  return res;
}

  "Ruisekiwa_moto": {
    "prefix": "Ruisekiwa_moto",
    "body": [
      "vi ruisekiwa_moto(vi &A){",
      "  int N=sz(A);",
      "  vi res(N,0);",
      "  res[0]=A[0];",
      "  rep(i,1,N) res[i]=A[i]-A[i-1];",
      "  return res;",
      "}"
    ],
    "description": "累積和の元を求める"
  },
  "部分和": {
    "prefix": "Bubunwa",
    "body": [
      "// Aのいくつかの要素の和がXになるか判定",
      "bool partial_sum(vi &A, int X){",
      "  bitset<1000005> bs(1);",
      "  fore(e,A) bs|=bs<<e;",
      "  if(bs[X]) return true;",
      "  else return false;",
      "}"
    ],
    "description": "部分和"
  },
  "拡張ユークリッドの互除法": {
    "prefix": "extgcd",
    "body": [
      "// ax+by=gcd(a,b)となるx,yを求める,戻り値はgcd(a,b)",
      "int extgcd(int a, int b, int &x, int &y){",
      "  if(b==0){ x = 1; y = 0; return a; }",
      "  int g=extgcd(b, a%b, y, x);",
      "  y-=a/b*x;",
      "  return g;",
      "}",
      "//int a=1029, b=1071, x, y;",
      "//int g=extgcd(a,b,x,y);",
      "printf(\"%lld x %lld + %lld x %lld = %lld\\n\", a, x, b, y, g);"
    ],
    "description": "拡張ユークリッドの互除法"
  },
  "中国剰余定理": {
    "prefix": "CRT",
    "body": [
// 負の数にも対応したmod
// -17(mod5)で-2でなく3を出力
inline int mod(int a, int m){
  return (a % m + m) % m;
}
// 拡張 Euclid の互除法
// ax+by=gcd(a,b)となるx,yを求める,戻り値はgcd(a,b)
int extgcd(int a, int b, int &x, int &y){
  if(b==0){ x = 1; y = 0; return a; }
  int g=extgcd(b, a%b, y, x);
  y-=a/b*x;
  return g;
}
// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
// ACL Contest1 Bの提出結果からするとbに負の数を渡しても問題なさそう
P ChineseRem(const vi &b, const vi &m) {
  int r = 0, M = 1;
  rep(i,0,sz(b)) {
    int p, q;
    int d = extgcd(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
    if ((b[i] - r) % d != 0) return make_pair(0, -1);
    int tmp = (b[i] - r) / d * p % (m[i]/d);
    r += M * tmp;
    M *= m[i]/d;
  }
  return make_pair(mod(r, M), M);
}
// 使用例
// 2(mod3)且つ3(mod5)且つ2(mod7)を求める
// P ans=ChineseRem({2,3,2},{3,5,7}); // ans=P(23,105) 23(mod105)
    ],
    "description": "拡張ユークリッドの互除法"
  },
  "グラフの受け取り": {
    "prefix": "get_graph",
    "body": [
      "vvi get_graph(){",
      "  int N,M;",
      "  cin >> N >> M;",
      "  vvi G(N);",
      "  rep(i,0,M){",
      "    int a,b;",
      "    cin >> a >> b;",
      "    a--; b--;",
      "    G[a].emplace_back(b);",
      "    G[b].emplace_back(a);",
      "  }",
      "  return G;",
      "}"
    ],
    "description": "グラフの受け取り"
  },
  "オイラーツアー": {
    "prefix": "EulerTour",
    "body": [
      // maspyさん:https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7
      "// segtreeにこれも必要",
      "int ceil_pow2(int n){",
      "  int x = 0;",
      "  while ((1U << x) < (unsigned int)(n)) x++;",
      "  return x;",
      "}",
      "",
      "template <class S, S (*op)(S, S), S (*e)()>",
      "struct segtree{",
      "public:",
      "  segtree() : segtree(0) {}",
      "  segtree(int n) : segtree(std::vector<S>(n, e())) {}",
      "  segtree(const std::vector<S> &v) : _n(ll(v.size())){",
      "    log = ceil_pow2(_n);",
      "    size = 1 << log;",
      "    d = std::vector<S>(2 * size, e());",
      "    for (int i = 0; i < _n; i++) d[size + i] = v[i];",
      "    for (int i = size - 1; i >= 1; i--) update(i);",
      "  }",
      "",
      "  void set(int p, S x){",
      "    assert(0 <= p && p < _n);",
      "    p += size;",
      "    d[p] = x;",
      "    for (int i = 1; i <= log; i++) update(p >> i);",
      "  }",
      "",
      "  S get(int p){",
      "    assert(0 <= p && p < _n);",
      "    return d[p + size];",
      "  }",
      "",
      "  S prod(int l, int r){",
      "    assert(0 <= l && l <= r && r <= _n);",
      "    S sml = e(), smr = e();",
      "    l += size;",
      "    r += size;",
      "",
      "    while (l < r){",
      "      if (l & 1) sml = op(sml, d[l++]);",
      "      if (r & 1) smr = op(d[--r], smr);",
      "      l >>= 1;",
      "      r >>= 1;",
      "    }",
      "    return op(sml, smr);",
      "  }",
      "",
      "  S all_prod() { return d[1]; }",
      "",
      "  template <bool (*f)(S)>",
      "  int max_right(int l){",
      "    return max_right(l, [](S x){ return f(x); });",
      "  }",
      "  template <class F>",
      "  int max_right(int l, F f){",
      "    assert(0 <= l && l <= _n);",
      "    assert(f(e()));",
      "    if (l == _n) return _n;",
      "    l += size;",
      "    S sm = e();",
      "    do{",
      "      while (l % 2 == 0) l >>= 1;",
      "      if (!f(op(sm, d[l]))){",
      "        while (l < size){",
      "          l = (2 * l);",
      "          if (f(op(sm, d[l]))){",
      "            sm = op(sm, d[l]);",
      "            l++;",
      "          }",
      "        }",
      "        return l - size;",
      "      }",
      "      sm = op(sm, d[l]);",
      "      l++;",
      "    } while ((l & -l) != l);",
      "    return _n;",
      "  }",
      "",
      "  template <bool (*f)(S)>",
      "  int min_left(int r){",
      "    return min_left(r, [](S x){ return f(x); });",
      "  }",
      "  template <class F>",
      "  int min_left(int r, F f){",
      "    assert(0 <= r && r <= _n);",
      "    assert(f(e()));",
      "    if (r == 0) return 0;",
      "    r += size;",
      "    S sm = e();",
      "    do{",
      "      r--;",
      "      while (r > 1 && (r % 2)) r >>= 1;",
      "      if (!f(op(d[r], sm))){",
      "        while (r < size){",
      "          r = (2 * r + 1);",
      "          if (f(op(d[r], sm))){",
      "            sm = op(d[r], sm);",
      "            r--;",
      "          }",
      "        }",
      "        return r + 1 - size;",
      "      }",
      "      sm = op(d[r], sm);",
      "    } while ((r & -r) != r);",
      "    return 0;",
      "  }",
      "",
      "private:",
      "  int _n, size, log;",
      "  std::vector<S> d;",
      "",
      "  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }",
      "};",
      "",
      "// RMQ(LCA用)",
      "P op_lca(P a,P b){return a.first<b.first?a:b;}",
      "P e_lca(){return P(INF,-1);}",
      "// RMQ(RangeMinimumQuery)",
      "//int op(int a,int b){return my_min(a,b);}",
      "//int e(){return INF;}",
      "// RMQ(RangeMaxQuery)",
      "//int op(int a,int b){return my_max(a,b);}",
      "//int e(){return 0;}",
      "// RSQ(RangeSumQuery)",
      "int op(int a,int b){return a+b;}",
      "int e(){return 0;}",
      "// GCDを乗せる",
      "//int op(int a,int b){return gcd(a,b);}",
      "//int e(){return 0;}",
      "// xorを乗せる",
      "//int op(int a,int b){return a^b;}",
      "//int e(){return 0;}",
      "",
      "template<typename G>",
      "struct EulerTour{",
      "  private:",
      "    int N; // 頂点数",
      "    int e_num; // 辺番号",
      "    G g; // グラフ",
      "    int d; // オイラーツアーの距離",
      "    vi in,out,tour; // tour:通った辺を並べる",
      "    vi depth; // 各頂点の深さ",
      "    vp enum_to_vertexs; // 辺番号→2つの頂点番号",
      "    // 部分木クエリ用",
      "    segtree<int,op,e> seg_subtree_vertex; // 頂点の合計",
      "    segtree<int,op,e> seg_subtree_edge; // 辺の合計",
      "    // パスクエリ用",
      "    segtree<int,op,e> seg_path_vertex; // 頂点の合計",
      "    segtree<int,op,e> seg_path_edge; // 辺の合計",
      "    // lcaクエリ用",
      "    segtree<P,op_lca,e_lca> seg_lca; // 深さの最小値",
      "",
      "    void init(int root){",
      "      dfs(g,root,-1,0,0);",
      "    }",
      "",
      "    void dfs(G &g, int cu, int p,int dp,int edge_weight){ // グラフ,現在の頂点,親,深さ,この頂点に至る際の辺の重さ",
      "      tour.emplace_back(cu+1); // オイラーツアー",
      "      if(p!=-1) seg_subtree_edge.set(d,edge_weight); // 辺の重さセット(部分木)",
      "      if(p!=-1) seg_path_edge.set(d,edge_weight); // 辺の重さセット(パス)",
      "      seg_lca.set(d,P(dp,cu)); // 深さ",
      "      depth[cu]=dp; // 深さ",
      "      in[cu]=d;",
      "      d++;",
      "",
      "      fore(e,g[cu]){",
      "        int nx,w;",
      "        tie(nx,w)=e;",
      "        if(nx==p) continue; // 親スキップ",
      "        dfs(g,nx,cu,dp+1,w);",
      "      }",
      "      out[cu]=d;",
      "      tour.emplace_back(-(cu+1)); // オイラーツアー",
      "      if(p!=-1) seg_path_edge.set(d,-edge_weight); // 辺の重さセット(パス)",
      "      if(p!=-1) seg_lca.set(d,P(dp-1,p)); // 深さ",
      "      d++;",
      "    }",
      "    ",
      "  public:",
      "    EulerTour(int n):N(n),e_num(0),d(0),g(n),in(n),out(n),depth(n),enum_to_vertexs(n-1),seg_subtree_vertex(n*2),seg_subtree_edge(n*2),seg_path_vertex(n*2),seg_path_edge(n*2),seg_lca(n*2){};",
      "    void add_edge(int u, int v, int w){",
      "      g[u].emplace_back(P(v,w));",
      "      g[v].emplace_back(P(u,w));",
      "      enum_to_vertexs[e_num++]=P(u,v);",
      "    }",
      "    void build(int root){",
      "      init(root);",
      "    }",
      "    // 変更==============================",
      "    // 頂点の重さを変更",
      "    void set_vertex_weight(int v, int w){",
      "      seg_subtree_vertex.set(in[v],w); // 部分木",
      "      seg_path_vertex.set(in[v],w); // パス",
      "      seg_path_vertex.set(out[v],-w); // パス",
      "    }",
      "    // 全頂点の重さを変更",
      "    void set_vertex_weight_all(vi ws){",
      "      rep(i,0,sz(ws)) set_vertex_weight(i,ws[i]);",
      "    }",
      "    // 辺の重さを変更(指定した頂点の親に接続された辺を変更する)",
      "    void set_edge_weight_p(int v, int w){",
      "      seg_subtree_edge.set(in[v],w); // 部分木",
      "      seg_path_edge.set(in[v],w); // パス",
      "      seg_path_edge.set(out[v],-w); // パス",
      "    }",
      "    // 辺の重さを変更(辺番号を指定)",
      "    void set_edge_weight_n(int num, int w){",
      "      int u,v;",
      "      tie(u,v)=enum_to_vertexs[num]; // 2つの頂点番号を得る",
      "      if(depth[u]<depth[v]) swap(u,v); // uを深い方にする",
      "      seg_subtree_edge.set(in[u],w); // 部分木",
      "      seg_path_edge.set(in[u],w); // パス",
      "      seg_path_edge.set(out[u],-w); // パス",
      "    }",
      "",
      "    // 部分木==============================",
      "    // 部分木の頂点の合計を得る",
      "    int subtree_vertex_sum(int v){",
      "      return seg_subtree_vertex.prod(in[v],out[v]);",
      "    }",
      "    // 部分木の辺の合計を得る",
      "    int subtree_edge_sum(int v){",
      "      return seg_subtree_edge.prod(in[v]+1,out[v]);",
      "    }",
      "    // パス==============================",
      "    // 根を始点とするパス上の頂点の合計を得る",
      "    int path_vertex_sum(int v){",
      "      return seg_path_vertex.prod(0,in[v]+1);",
      "    }",
      "    // 頂点間のパス上の頂点の合計を得る",
      "    int path_vertex_sum_2v(int a, int b){",
      "      int lca=get_lca(a,b);",
      "      int d_a=path_vertex_sum(a);",
      "      int d_b=path_vertex_sum(b);",
      "      int d_cmn=path_vertex_sum(lca);",
      "      return d_a + d_b - d_cmn*2 + seg_path_vertex.get(in[lca]);",
      "    }",
      "    // 根を始点とするパス上の辺の合計を得る",
      "    int path_edge_sum(int v){",
      "      return seg_path_edge.prod(0,in[v]+1);",
      "    }",
      "    // 頂点間のパス上の辺の合計を得る",
      "    int path_edge_sum_2v(int a, int b){",
      "      int lca=get_lca(a,b);",
      "      int d_a=path_edge_sum(a);",
      "      int d_b=path_edge_sum(b);",
      "      int d_cmn=path_edge_sum(lca);",
      "      return d_a + d_b - d_cmn*2;",
      "    }",
      "    // LCA==============================",
      "    // LCAを求める",
      "    int get_lca(int a, int b){",
      "      if(in[a]>in[b]) swap(a,b);",
      "      return seg_lca.prod(in[a],in[b]+1).second;",
      "    }",
      "    // LCA,深さを求める",
      "    P get_lca_depth(int a, int b){",
      "      if(in[a]>in[b]) swap(a,b);",
      "      P depth_lca=seg_lca.prod(in[a],in[b]+1);",
      "      return P(depth_lca.second,depth_lca.first); // 使いやすさのため入れ替える",
      "    }",
      "};"
    ],
    "description": "オイラーツアー(セグ木入り)"
  },
  "オイラーツアーの使い方": {
    "prefix": "EulerTour-Use",
    "body": [
      "// ☆構築==============================",
      "EulerTour<vvp> et(N);               // 頂点数で初期化",
      "rep(i,0,N-1){",
      "  int u,v,w;",
      "  cin >> u >> v >> w;",
      "  u--; v--;",
      "  et.add_edge(u,v,w);               // 辺を追加(双方向に追加される)",
      "}",
      "et.build(0);                        // 構築(根を渡す)",
      "vi ws={1,2,3,4,5,6};                // 各頂点の重み(不要なら渡さなくてよい)",
      "et.set_vertex_weight_all(ws);       // 全頂点に重みを設定する(不要なら実行しなくてよい)",
      "// ☆変更==============================",
      "et.set_vertex_weight(v,w);          // 指定頂点の重み変更",
      "et.set_edge_weight_n(i,w);          // 辺の重さを変更(辺番号を指定)",
      "et.set_edge_weight_p(v,w);          // 指定辺の重み変更(指定した頂点の親に接続された辺を変更する)",
      "// ☆クエリ処理(部分木)==============================",
      "int ans=et.subtree_vertex_sum(v);   // 頂点の重さの和",
      "int ans=et.subtree_edge_sum(v);     // 辺の重さの和",
      "// ☆クエリ処理(パス)==============================",
      "int ans=et.path_vertex_sum(v);      // 根からの頂点の重さの和",
      "int ans=et.path_edge_sum(v);        // 根からの辺の重さの和",
      "int ans=et.path_vertex_sum_2v(u,v); // 2頂点間の頂点の重さの和",
      "int ans=et.path_edge_sum_2v(u,v);   // 2頂点間の辺の重さの和",
      "// ☆クエリ処理(LCA)==============================",
      "int lca=et.get_lca(v);              // LCA",
      "P lca_depth=et.get_lca_depth(2,3);  // LCAとその深さ"
    ],
    "description": "オイラーツアーの使い方"
  },
  "オイラーツアー-グラフを渡すバージョン": {
    "prefix": "EulerTour-old",
    "body": [
      // maspyさん:https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7
      "// segtreeにこれも必要",
      "int ceil_pow2(int n){",
      "  int x = 0;",
      "  while ((1U << x) < (unsigned int)(n)) x++;",
      "  return x;",
      "}",
      "",
      "template <class S, S (*op)(S, S), S (*e)()>",
      "struct segtree{",
      "public:",
      "  segtree() : segtree(0) {}",
      "  segtree(int n) : segtree(std::vector<S>(n, e())) {}",
      "  segtree(const std::vector<S> &v) : _n(ll(v.size())){",
      "    log = ceil_pow2(_n);",
      "    size = 1 << log;",
      "    d = std::vector<S>(2 * size, e());",
      "    for (int i = 0; i < _n; i++) d[size + i] = v[i];",
      "    for (int i = size - 1; i >= 1; i--) update(i);",
      "  }",
      "",
      "  void set(int p, S x){",
      "    assert(0 <= p && p < _n);",
      "    p += size;",
      "    d[p] = x;",
      "    for (int i = 1; i <= log; i++) update(p >> i);",
      "  }",
      "",
      "  S get(int p){",
      "    assert(0 <= p && p < _n);",
      "    return d[p + size];",
      "  }",
      "",
      "  S prod(int l, int r){",
      "    assert(0 <= l && l <= r && r <= _n);",
      "    S sml = e(), smr = e();",
      "    l += size;",
      "    r += size;",
      "",
      "    while (l < r){",
      "      if (l & 1) sml = op(sml, d[l++]);",
      "      if (r & 1) smr = op(d[--r], smr);",
      "      l >>= 1;",
      "      r >>= 1;",
      "    }",
      "    return op(sml, smr);",
      "  }",
      "",
      "  S all_prod() { return d[1]; }",
      "",
      "  template <bool (*f)(S)>",
      "  int max_right(int l){",
      "    return max_right(l, [](S x){ return f(x); });",
      "  }",
      "  template <class F>",
      "  int max_right(int l, F f){",
      "    assert(0 <= l && l <= _n);",
      "    assert(f(e()));",
      "    if (l == _n) return _n;",
      "    l += size;",
      "    S sm = e();",
      "    do{",
      "      while (l % 2 == 0) l >>= 1;",
      "      if (!f(op(sm, d[l]))){",
      "        while (l < size){",
      "          l = (2 * l);",
      "          if (f(op(sm, d[l]))){",
      "            sm = op(sm, d[l]);",
      "            l++;",
      "          }",
      "        }",
      "        return l - size;",
      "      }",
      "      sm = op(sm, d[l]);",
      "      l++;",
      "    } while ((l & -l) != l);",
      "    return _n;",
      "  }",
      "",
      "  template <bool (*f)(S)>",
      "  int min_left(int r){",
      "    return min_left(r, [](S x){ return f(x); });",
      "  }",
      "  template <class F>",
      "  int min_left(int r, F f){",
      "    assert(0 <= r && r <= _n);",
      "    assert(f(e()));",
      "    if (r == 0) return 0;",
      "    r += size;",
      "    S sm = e();",
      "    do{",
      "      r--;",
      "      while (r > 1 && (r % 2)) r >>= 1;",
      "      if (!f(op(d[r], sm))){",
      "        while (r < size){",
      "          r = (2 * r + 1);",
      "          if (f(op(d[r], sm))){",
      "            sm = op(d[r], sm);",
      "            r--;",
      "          }",
      "        }",
      "        return r + 1 - size;",
      "      }",
      "      sm = op(d[r], sm);",
      "    } while ((r & -r) != r);",
      "    return 0;",
      "  }",
      "",
      "private:",
      "  int _n, size, log;",
      "  std::vector<S> d;",
      "",
      "  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }",
      "};",
      "",
      "// RMQ(RangeMinimumQuery)",
      "P op_rmq(P a,P b){return a.first<b.first?a:b;}",
      "P e_rmq(){return P(INF,-1);}",
      "// RMQ(RangeMaxQuery)",
      "//int op(int a,int b){return my_max(a,b);}",
      "//int e(){return 0;}",
      "// RSQ(RangeSumQuery)",
      "int op(int a,int b){return a+b;}",
      "int e(){return 0;}",
      "// GCDを乗せる",
      "//int op(int a,int b){return gcd(a,b);}",
      "//int e(){return 0;}",
      "// xorを乗せる",
      "//int op(int a,int b){return a^b;}",
      "//int e(){return 0;}",
      "",
      "template<typename G>",
      "struct EulerTour{",
      "  private:",
      "    int d; // オイラーツアーの距離",
      "    vi in,out,tour; // tour:通った辺を並べる",
      "    //vi depth; // 各頂点の深さ",
      "    // 部分木クエリ用",
      "    segtree<int,op,e> seg_subtree_vertex; // 頂点の合計",
      "    segtree<int,op,e> seg_subtree_edge; // 辺の合計",
      "    // パスクエリ用",
      "    segtree<int,op,e> seg_path_vertex; // 頂点の合計",
      "    segtree<int,op,e> seg_path_edge; // 辺の合計",
      "    // lcaクエリ用",
      "    segtree<P,op_rmq,e_rmq> seg_lca; // 深さの最小値",
      "",
      "    void init(G &g, int root){",
      "      dfs(g,root,-1,0,0);",
      "    }",
      "",
      "    void dfs(G &g, int cu, int p,int dp,int edge_weight){ // グラフ,現在の頂点,親,深さ,この頂点に至る際の辺の重さ",
      "      tour.emplace_back(cu+1); // オイラーツアー",
      "      if(p!=-1) seg_subtree_edge.set(d,edge_weight); // 辺の重さセット(部分木)",
      "      if(p!=-1) seg_path_edge.set(d,edge_weight); // 辺の重さセット(パス)",
      "      seg_lca.set(d,P(dp,cu)); // 深さ",
      "      in[cu]=d;",
      "      d++;",
      "",
      "      fore(e,g[cu]){",
      "        int nx,w;",
      "        tie(nx,w)=e;",
      "        if(nx==p) continue; // 親スキップ",
      "        dfs(g,nx,cu,dp+1,w);",
      "      }",
      "      out[cu]=d;",
      "      tour.emplace_back(-(cu+1)); // オイラーツアー",
      "      if(p!=-1) seg_path_edge.set(d,-edge_weight); // 辺の重さセット(パス)",
      "      if(p!=-1) seg_lca.set(d,P(dp-1,p)); // 深さ",
      "      d++;",
      "    }",
      "    ",
      "  public:",
      "    EulerTour(G &g, int root):d(0),in(sz(g)),out(sz(g)),seg_subtree_vertex(sz(g)*2),seg_subtree_edge(sz(g)*2),seg_path_vertex(sz(g)*2),seg_path_edge(sz(g)*2),seg_lca(sz(g)*2) {",
      "      init(g,root);",
      "    }",
      "    // 変更==============================",
      "    // 頂点の重さを変更",
      "    void set_vertex_weight(int v, int w){",
      "      seg_subtree_vertex.set(in[v],w); // 部分木",
      "      seg_path_vertex.set(in[v],w); // パス",
      "      seg_path_vertex.set(out[v],-w); // パス",
      "    }",
      "    // 全頂点の重さを変更",
      "    void set_vertex_weight_all(vi ws){",
      "      rep(i,0,sz(ws)) set_vertex_weight(i,ws[i]);",
      "    }",
      "    // 辺の重さを変更(指定した頂点の親に接続された辺を変更する)",
      "    void set_edge_weight(int v, int w){",
      "      seg_subtree_edge.set(in[v],w); // 部分木",
      "      seg_path_edge.set(in[v],w); // パス",
      "      seg_path_edge.set(out[v],-w); // パス",
      "    }",
      "    // 部分木==============================",
      "    // 部分木の頂点の合計を得る",
      "    int subtree_vertex_sum(int v){",
      "      return seg_subtree_vertex.prod(in[v],out[v]);",
      "    }",
      "    // 部分木の辺の合計を得る",
      "    int subtree_edge_sum(int v){",
      "      return seg_subtree_edge.prod(in[v]+1,out[v]);",
      "    }",
      "    // パス==============================",
      "    // 根を始点とするパス上の頂点の合計を得る",
      "    int path_vertex_sum(int v){",
      "      return seg_path_vertex.prod(0,in[v]+1);",
      "    }",
      "    // 頂点間のパス上の頂点の合計を得る",
      "    int path_vertex_sum_2v(int a, int b){",
      "      int lca=get_lca(a,b);",
      "      int d_a=path_vertex_sum(a);",
      "      int d_b=path_vertex_sum(b);",
      "      int d_cmn=path_vertex_sum(lca);",
      "      return d_a + d_b - d_cmn*2 + seg_path_vertex.get(in[lca]);",
      "    }",
      "    // 根を始点とするパス上の辺の合計を得る",
      "    int path_edge_sum(int v){",
      "      return seg_path_edge.prod(0,in[v]+1);",
      "    }",
      "    // 頂点間のパス上の辺の合計を得る",
      "    int path_edge_sum_2v(int a, int b){",
      "      int lca=get_lca(a,b);",
      "      int d_a=path_edge_sum(a);",
      "      int d_b=path_edge_sum(b);",
      "      int d_cmn=path_edge_sum(lca);",
      "      return d_a + d_b - d_cmn*2;",
      "    }",
      "    // LCA==============================",
      "    // LCAを求める",
      "    int get_lca(int a, int b){",
      "      if(in[a]>in[b]) swap(a,b);",
      "      return seg_lca.prod(in[a],in[b]+1).second;",
      "    }",
      "    // LCA,深さを求める",
      "    P get_lca_depth(int a, int b){",
      "      if(in[a]>in[b]) swap(a,b);",
      "      P depth_lca=seg_lca.prod(in[a],in[b]+1);",
      "      return P(depth_lca.second,depth_lca.first); // 使いやすさのため入れ替える",
      "    }",
      "};"
    ],
    "description": "オイラーツアー(セグ木入り)-グラフを渡すバージョン"
  },
  "オイラーツアーの使い方-グラフを渡すバージョン": {
    "prefix": "EulerTour-Use-old",
    "body": [
      "// ☆構築==============================",
      "vvp G(N);",
      "rep(i,0,N-1){",
      "  int u,v,w;",
      "  cin >> u >> v >> w;",
      "  u--; v--;",
      "  G[u].emplace_back(P(v,w));",
      "  G[v].emplace_back(P(u,w));",
      "}",
      "EulerTour<vvp> et(G,0);             // 木のグラフ(辺の重みはここで渡す),根",
      "vi ws={1,2,3,4,5,6};                // 各頂点の重み(不要なら渡さなくてよい)",
      "et.set_vertex_weight_all(ws);       // 全頂点に重みを設定する",
      "// ☆変更==============================",
      "et.set_vertex_weight(v,w);          // 指定頂点の重み変更",
      "et.set_edge_weight(v,w);            // 指定辺の重み変更(指定した頂点の親に接続された辺を変更する)",
      "// ☆クエリ処理(部分木)==============================",
      "int ans=et.subtree_vertex_sum(v);   // 頂点の重さの和",
      "int ans=et.subtree_edge_sum(v);     // 辺の重さの和",
      "// ☆クエリ処理(パス)==============================",
      "int ans=et.path_vertex_sum(v);      // 根からの頂点の重さの和",
      "int ans=et.path_edge_sum(v);        // 根からの辺の重さの和",
      "int ans=et.path_vertex_sum_2v(u,v); // 2頂点間の頂点の重さの和",
      "int ans=et.path_edge_sum_2v(u,v);   // 2頂点間の辺の重さの和",
      "// ☆クエリ処理(LCA)==============================",
      "int lca=et.get_lca(v);              // LCA",
      "P lca_depth=et.get_lca_depth(2,3);  // LCAとその深さ"
    ],
    "description": "オイラーツアーの使い方-グラフを渡すバージョン"
  },
  "極座標系での回転": {
    "prefix": "PolarRot",
    "body": [
      "using C = complex<double>;",
      "// 度をラジアンに変換",
      "double deg2rad(double d){return d/180.0*M_PI;}",
      "// cを原点を中心に回転(度)",
      "C rot_around_origin_deg(C c, double deg){",
      "  double rad=deg2rad(deg);",
      "  C r(cos(rad),sin(rad)); // 回転用の複素数",
      "  return c*r;",
      "}",
      "// cを原点を中心に回転(ラジアン)",
      "C rot_around_origin_rad(C c, double rad){",
      "  C r(cos(rad),sin(rad)); // 回転用の複素数",
      "  return c*r;",
      "}",
      "// c1をc2を中心に回転(度)",
      "C rot_around_point_deg(C c1, C c2, double deg){",
      "  return rot_around_origin_deg(c1-c2,deg)+c2;",
      "}",
      "// c1をc2を中心に回転(ラジアン)",
      "C rot_around_point_rad(C c1, C c2, double rad){",
      "  return rot_around_origin_rad(c1-c2,rad)+c2;",
      "}",
      "// 使い方",
      "int x1=1,y1=1,x2=1,y2=0,d=90;",
      "double r=M_PI/2;",
      "C c1(x1,y1),c2(x2,y2);",
      "// c1を原点を中心に回転(度)",
      "C c=rot_around_origin_deg(c1,d);",
      "// c1を原点を中心に回転(ラジアン)",
      "c=rot_around_origin_rad(c1,r);",
      "// c1をc2を中心に回転(度)",
      "c=rot_around_point_deg(c1,c2,d);",
      "// c1をc2を中心に回転(ラジアン)",
      "c=rot_around_point_rad(c1,c2,r);",
      "// 出力(問題文を見て精度に注意)",
      "printf(\"%.15lf %.15lf\\n\",c.real(),c.imag());"
    ],
    "description": "極座標系での回転"
  },
  "直交座標系での回転": {
    "prefix": "CartesianRot",
    "body": [
      "// 度をラジアンに変換",
      "double deg2rad(double d){return d/180.0*M_PI;}",
      "// 点を原点を中心に回転(度)",
      "pair<double,double> rot_around_origin_deg(double x, double y, double d){",
      "  double r=deg2rad(d);",
      "  return make_pair(x*cos(r)-y*sin(r),x*sin(r)+y*cos(r));",
      "}",
      "// 点を原点を中心に回転(ラジアン)",
      "pair<double,double> rot_around_origin_rad(double x, double y, double r){",
      "  return make_pair(x*cos(r)-y*sin(r),x*sin(r)+y*cos(r));",
      "}",
      "// 点(x1,y1)を特定座標(x2,y2)を中心に回転(度)",
      "pair<double,double> rot_around_point_deg(double x1, double y1, double x2, double y2, double d){",
      "  pair<double,double> a=rot_around_origin_deg(x1-x2,y1-y2,d);",
      "  return make_pair(a.first+x2,a.second+y2);",
      "}",
      "// 点(x1,y1)を特定座標(x2,y2)を中心に回転(ラジアン)",
      "pair<double,double> rot_around_point_rad(double x1, double y1, double x2, double y2, double r){",
      "  pair<double,double> a=rot_around_origin_rad(x1-x2,y1-y2,r);",
      "  return make_pair(a.first+x2,a.second+y2);",
      "}",
      "// 使い方",
      "int x1=1,y1=1,x2=1,y2=0,d=90;",
      "double r=M_PI/2;",
      "// 点を原点を中心に回転(度)",
      "pair<double,double> res1=rot_around_origin_deg(x1,y1,d);",
      "// 点を原点を中心に回転(ラジアン)",
      "pair<double,double> res2=rot_around_origin_rad(x1,y1,r);",
      "// 点(x1,y1)を特定座標(x2,y2)を中心に回転(度)",
      "pair<double,double> res3=rot_around_point_deg(x1,y1,x2,y2,d);",
      "// 点(x1,y1)を特定座標(x2,y2)を中心に回転(ラジアン)",
      "pair<double,double> res4=rot_around_point_rad(x1,y1,x2,y2,r);",
      "// 出力(問題文を見て精度に注意)",
      "printf(\"%.15lf %.15lf\\n\",res1.first,res1.second);"
    ],
    "description": "直交座標系での回転"
  },
  "ラムダ式の書き方": {
    "prefix": "Lambda-Format",
    "body": [
      "// ラムダ式",
      "// 引数なし",
      "auto f=[&]{",
      "  // 処理",
      "};",
      "// 引数あり",
      "auto f=[&](int a){",
      "  // 処理",
      "};",
      "// 引数あり,戻り値あり",
      "auto f=[&](int a) -> int {",
      "  return a+1;",
      "};",
      "// 引数あり,戻り値あり,再帰",
      "auto dfs=[&](auto f, int a) -> int {",
      "  ",
      "  return a+1;",
      "};",
      "int ans=dfs(dfs,1); // 使用時",
      "// 再帰2",
      "auto dfs=[&](auto f, int cu) -> void {",
      "  fore(next_v,G[cu]){",
      "    if(dist[next_v]!=-1) continue;",
      "    dist[next_v]=dist[cu]+1;",
      "    f(f,next_v);",
      "  }",
      "};",
      "dfs(dfs,0); //使用時"
    ],
    "description": "ラムダ式の書き方"
  },
  "dfs": {
    "prefix": "dfs",
    "body": [
      "vvi G(N);",
      "auto dfs=[&](auto &f, int cu, int pa) -> void {",
      "  // 行きがけ順の処理をここに書く",
      "  fore(nx,G[cu]){",
      "    if(nx==pa) continue;",
      "    f(f,nx,cu);",
      "  }",
      "  // 帰りがけ順の処理をここに書く",
      "};",
      "// dfs(dfs,0,-1); // 使い方"
    ],
    "description": "dfs"
  },
  "グリッド上の距離": {
    "prefix": "grid_dist",
    "body": [
      "bool is_outer_range(int R1,int r1,int R2,int r2){",
      "  return (r1<0 or R1<=r1 or r2<0 or R2<=r2);",
      "}",
      "vvi grid_dist(vs &S, int sx, int sy){",
      "  int _H=sz(S),_W=sz(S[0]);",
      "  vvi dist(_H,vi(_W,INF));",
      "  dist[sx][sy]=0;",
      "  queue<P> q;",
      "  q.push(P(sx,sy));",
      "  while(!q.empty()){",
      "    int x,y;",
      "    tie(x,y)=q.front(); q.pop();",
      "    rep(dir,0,4){",
      "      int nx=x+dx[dir];",
      "      int ny=y+dy[dir];",
      "      if(is_outer_range(_H,nx,_W,ny)) continue;",
      "      if(S[nx][ny]=='#') continue;",
      "      if(chmin(dist[nx][ny],dist[x][y]+1)) q.push(P(nx,ny));",
      "    }",
      "  }",
      "  return dist;",
      "}",
      "//vs S(H);",
      "//int sx=0,sy=0;",
      "//vvi dist=grid_dist(S,sx,sy);"
    ],
    "description": "グリッド上の距離"
  },
  "桁DP": {
    "prefix": "keta_DP",
    "body": [
      "// TDPC E - 数",
      "// N以下の正整数であって各桁の和がDの倍数であるものの個数をmod1000000007で求めよ。",
      "int D;",
      "string S;",
      "cin >> D >> S;",
      "int N=sz(S);",
      "vector<vector<mint>> dp(2,vector<mint>(D)); // dp(桁数)[isless][剰余]=パターン数",
      "dp[0][0]=1;",
      "rep(i,0,N){ // 見ている桁",
      "  vector<vector<mint>> buf(2,vector<mint>(D));",
      "  int d=S[i]-'0'; // 今回の上限の数字",
      "  rep(isless,0,2){ // isless",
      "    rep(x,0,(isless?10:d+1)){ // 今回使う数字",
      "      rep(m,0,D){ // 剰余",
      "        buf[isless | (x<d)][(m+x)%D]+=dp[isless][m];",
      "      }",
      "    }",
      "  }",
      "  swap(dp,buf);",
      "}",
      "mint ans=dp[0][0]+dp[1][0]-1;",
      "fo(ans);"
    ],
    "description": "桁DP"
  },
  "bitDP": {
    "prefix": "bit_DP",
    "body": [
      "// 鉄則 B23 - Traveling Salesman Problem",
      "int N;",
      "cin >> N;",
      "vi X(N),Y(N);",
      "rep(i,0,N) cin >> X[i] >> Y[i];",
      "vector<vector<double>> dp(1<<N,vector<double>(N,INF));",
      "dp[0][0]=0;",
      "rep(S,0,1<<N){",
      "  // 元",
      "  rep(u,0,N){",
      "    if(dp[S][u]>=INF) continue; // 未到達スキップ",
      "    // 先",
      "    rep(v,0,N){",
      "      if(S&(1<<v)) continue; // 訪問済みスキップ",
      "      int dx=X[v]-X[u];",
      "      int dy=Y[v]-Y[u];",
      "      double d=sqrt(dx*dx + dy*dy);",
      "      chmin(dp[S|1<<v][v],dp[S][u]+d);",
      "    }",
      "  }",
      "}",
      "printf(\"%.10lf\\n\",dp[(1<<N)-1][0]);"
    ],
    "description": "bitDP"
  },
  "LowLink": {
    "prefix": "LowLink",
    "body": [
      "struct LowLink {",
      "  const vvi &G;",
      "  vector<int> used, ord, low; // order:行きがけ順の番号,low:後退辺1つで行けるordのmin",
      "  vector<int> aps;  // articulation points",
      "  vector<P> bridges;",
      "  LowLink(const vvi &G_) : G(G_) {",
      "    used.assign(G.size(), 0);",
      "    ord.assign(G.size(), 0);",
      "    low.assign(G.size(), 0);",
      "    int k=0;",
      "    rep(i,0,(int)G.size()){",
      "      if(!used[i]) k = dfs(i, k, -1);",
      "    }",
      "    sort(all(aps)); // 必要ならソートする",
      "    sort(all(bridges)); // 必要ならソートする",
      "  }",
      "  int dfs(int id, int k, int par) { // id:探索中の頂点, k:dfsで何番目に探索するか, par:idの親",
      "    used[id]=true;",
      "    ord[id]=k++;",
      "    low[id]=ord[id];",
      "    bool is_aps = false;",
      "    int count = 0; // 子の数",
      "    fore(e,G[id]) {",
      "      if(!used[e]) {",
      "        count++;",
      "        k = dfs(e, k, id);",
      "        low[id] = min(low[id], low[e]);",
      "        if(par != -1 && ord[id] <= low[e]) is_aps = true; ",
      "        if(ord[id] < low[e]) bridges.emplace_back(min(id, e), max(id, e)); // 条件を満たすので橋  ",
      "      }else if(e != par) { // eが後退辺の時",
      "        low[id] = min(low[id], ord[e]);",
      "      }",
      "    }",
      "    if (par == -1 && count >= 2) is_aps = true; ",
      "    if (is_aps) aps.push_back(id);",
      "    return k;",
      "  }",
      "};"
    ],
    "description": "LowLink"
  },
  "LowLink-use": {
    "prefix": "LowLink-use",
    "body": [
      "// 作成: O(E+V)",
      "// 関節点の集合: vector<int> aps",
      "// 橋の集合: vector<P> bridges",
      "LowLink lo_li=LowLink(G);",
      "fo(sz(lo_li.bridges));"
    ],
    "description": "LowLink-use"
  },
  "mendo": {
    "prefix": "mendo",
    "body": [
      "// vsをCW90度回転",
      "vs rot_CW90(vs A){",
      "  int _H=sz(A);",
      "  int _W=sz(A[0]);",
      "  vs res(_W);",
      "  rep(j,0,_W){",
      "    string buf=\"\";",
      "    for(int i=_H-1; i>=0;--i){",
      "      buf+=A[i][j];",
      "    }",
      "    res[j]=buf;",
      "  }",
      "  return res;",
      "}",
      "// vsをCCW90度回転",
      "vs rot_CCW90(vs A){",
      "  int _H=sz(A);",
      "  int _W=sz(A[0]);",
      "  vs res(_W);",
      "  for(int j=_W-1; j>=0; --j){",
      "    string buf=\"\";",
      "    rep(i,0,_H){",
      "      buf+=A[i][j];",
      "    }",
      "    res[_W-1-j]=buf;",
      "  }",
      "  return res;",
      "}",
      "// vsから'.'のみの領域を削除,何も残らない場合はres[0][0]='_'を返す",
      "vs trim(vs A){",
      "  int _H=sz(A);",
      "  int _W=sz(A[0]);",
      "  int mn_x=sz(A),mx_x=0;",
      "  int mn_y=sz(A[0]),mx_y=0;",
      "  rep(i,0,_H){",
      "    rep(j,0,_W){",
      "      if(A[i][j]=='.') continue;",
      "      chmax(mx_x,i);",
      "      chmin(mn_x,i);",
      "      chmax(mx_y,j);",
      "      chmin(mn_y,j);",
      "    }",
      "  }",
      "  if(mx_x<mn_x){",
      "    return {\"_\"};",
      "  }",
      "  vs res;",
      "  rep(i,mn_x,mx_x+1){",
      "    string buf=\"\";",
      "    rep(j,mn_y,mx_y+1){",
      "      buf+=A[i][j];",
      "    }",
      "    res.emplace_back(buf);",
      "  }",
      "  return res;",
      "}"
    ],
    "description": "面倒な処理をまとめたもの"
  },
  "hanbun": {
    "prefix": "hanbun",
    "body": [
      "unordered_map<int,int> bit_z(vi v){",
      "  int N=sz(v);",
      "  unordered_map<int,int> mp;",
      "  rep(bit,0,1<<N){",
      "    int sum=0;",
      "    rep(i,0,N){",
      "      // プラス",
      "      if(bit>>i & 1){",
      "        sum+=v[i];",
      "      // マイナス",
      "      }else{",
      "        sum-=v[i];",
      "      }",
      "    }",
      "    mp[sum]=bit;",
      "  }",
      "  return mp;",
      "}",
      "string hanbun(vi A, int x){",
      "  vi v1,v2;",
      "  int N=sz(A);",
      "  int N1=N/2;",
      "  int N2=N-N1;",
      "  rep(i,0,N1) v1.emplace_back(A[i]);",
      "  rep(i,N1,N) v2.emplace_back(A[i]);",
      "",
      "  unordered_map<int,int> mp1=bit_z(v1);",
      "  unordered_map<int,int> mp2=bit_z(v2);",
      "  set<int> st;",
      "  fore(e,mp2) st.insert(e.first);",
      "",
      "  fore(e,mp1){",
      "    int n1=e.first;",
      "    if(st.count(x-n1)){",
      "      string ope=\"\";",
      "      int bit1=mp1[n1];",
      "      rep(i,0,sz(v1)){",
      "        if((bit1>>i)&1) ope+='p';",
      "        else ope+='m';",
      "      }",
      "      int bit2=mp2[x-n1];",
      "      rep(i,0,sz(v2)){",
      "        if((bit2>>i)&1) ope+='p';",
      "        else ope+='m';",
      "      }",
      "      return ope;",
      "    }",
      "  }",
      "",
      "  // 到達不可能の場合",
      "  return \"-1\";",
      "}",
      "// 使い方",
      "// Aの各要素をプラス(p),マイナス(m)にしてtarにする組み合わせを求める",
      "// 不可なら\"-1\"を出力",
      "vi A(N); // N=40程度まで",
      "int tar=5;",
      "string S_tate=hanbun(A,tar);"
    ],
    "description": "半分全列挙"
  },
  "combination": {
    "prefix": "combination",
    "body": [
// 選択の具体的な内容を返す
vvi combination(vi lis, int r){
  vvi res;
  int N=sz(lis);
  vi S;
  auto dfs=[&](auto &f, int cu) -> void {
    if(sz(S)==r){
      res.emplace_back(S);
      return;
    }
    // 今回追加するものをまわす
    rep(i,cu,N){
      S.emplace_back(i);
      f(f,i+1);
      S.pop_back();
    }
  };
  dfs(dfs,0);
  return res;
}
// 使い方(N個からR個選ぶとする)
vi cand(N);
iota(all(cand),0);
vvi sel=combination(cand,R);
    ],
    "description": "組み合わせを作る"
  },
// "Template"==================================================
// "prefix": "temp",
// "description": "C++テンプレート"

// "permutation"==================================================
// "prefix": "permutation",
// "description": "順列"
int n=4;
vi v(n);
iota(all(v),0);
do{
  //vは次の順列になる
  rep(i,0,n){
    //なんらかの操作
  }
}while(next_permutation(all(v)));

  "ushi1": {
    "prefix": "ushi1",
    "body": [
      "// 牛ゲー1(負辺なし)",
      "// ある距離以内にしたい関係がM個与えられ,全区間の最大距離を求める",
      "",
      "// グラフと始点を渡すと各頂点への最短距離を返すダイクストラ",
      "struct Edge{",
      "  int to,co;",
      "  Edge(int to=0, int co=0): to(to), co(co) {}",
      "};",
      "vi dijkstra(vector<vector<Edge>> &g, int s){",
      "  vi dist(g.size(), INF);",
      "  min_priority_queue<P> q;",
      "  dist[s] = 0;",
      "  q.emplace(dist[s],s);",
      "  while(!q.empty()){",
      "    int d,cu;",
      "    tie(d,cu)=q.top(); q.pop();",
      "    if(dist[cu] < d) continue;",
      "    fore(e,g[cu]){",
      "      if(chmin(dist[e.to],d+e.co)){",
      "        q.emplace(dist[e.to],e.to);",
      "      }",
      "    }",
      "  }",
      "  return dist;",
      "}",
      "",
      "void out_vec_with_space(vector<auto> &v){",
      "  for (int i = 0; i < v.size(); i++){",
      "    cout << ( i ? \" \" : \"\" ) << v[i];",
      "  }",
      "  cout << endl;",
      "}",
      "",
      "signed main(){",
      "  int N,M;",
      "  cin >> N >> M;",
      "",
      "  vector<vector<Edge>> G(N);",
      "  rep(i,0,N-1) G[i].emplace_back(Edge(i+1,1)); // 0→1に1の辺",
      "  rep(i,0,N-1) G[i+1].emplace_back(Edge(i,0)); // 0←1に0の辺",
      "  ",
      "  rep(i,0,M){",
      "    int u,v,c;",
      "    cin >> u >> v >> c;",
      "    u--; v--;",
      "    G[u].emplace_back(Edge(v,c)); // u→vにcの辺を張る(v<=u+cを表現)",
      "  }",
      "  vi dist=dijkstra(G,0); // 頂点0を始点とする各頂点への距離",
      "",
      "  // 最大距離を求める",
      "  fo(dist[N]);",
      "  ",
      "  // 隣の頂点との距離を求める",
      "  // vi ans(N-1);",
      "  // rep(i,0,N-1) ans[i]=dist[i+1]-dist[i];",
      "  // out_vec_with_space(ans);",
      "}"
    ],
    "description": "牛ゲー1(負辺なし)"
  },
  "ushi2": {
    "prefix": "ushi2",
    "body": [
      "// 牛ゲー2(負辺あり)",
      "// ある距離以内/以上にしたい関係がM個与えられ,全区間の最大距離を求める",
      "// 負閉路を持つ場合はそのような関係は存在しない,dist[N-1]==INFの場合は無限に離れられる",
      "",
      "// グラフと始点を渡すと各頂点への最短距離を返すベルマンフォード(負閉路を持つ場合は{}を返す)",
      "struct Edge{",
      "  int to,co;",
      "  Edge(int to=0, int co=0): to(to), co(co) {}",
      "};",
      "vi bellman_ford(vector<vector<Edge>> &g, int s){",
      "  bool exist_negative_cycle=false; // 負閉路を持つか",
      "  vi dist(g.size(), INF);",
      "  dist[s] = 0;",
      "  int N=sz(g);",
      "  rep(i,0,N){",
      "    bool update=false; // 更新有無を記録",
      "    rep(v,0,N){",
      "      if(dist[v]==INF) continue;",
      "      fore(e,g[v]){",
      "        if(chmin(dist[e.to],dist[v]+e.co)) update=true;",
      "      }",
      "    }",
      "    if(!update) break; // 更新がなくなったら既に最短経路が求められている",
      "    if(i==N-1 and update) exist_negative_cycle=true; // N回目の反復で更新が行われたならば、負閉路をもつ",
      "  }",
      "  if(exist_negative_cycle) return {};",
      "  return dist;",
      "}",
      "",
      "void out_vec_with_space(vector<auto> &v){",
      "  for (int i = 0; i < v.size(); i++){",
      "    cout << ( i ? \" \" : \"\" ) << v[i];",
      "  }",
      "  cout << endl;",
      "}",
      "",
      "signed main(){",
      "  int N,M;",
      "  cin >> N >> M;",
      "",
      "  vector<vector<Edge>> G(N);",
      "  rep(i,0,N-1) G[i].emplace_back(Edge(i+1,1)); // 0→1に1の辺",
      "  rep(i,0,N-1) G[i+1].emplace_back(Edge(i,0)); // 0←1に0の辺",
      "  ",
      "  rep(i,0,M){",
      "    int u,v,c;",
      "    cin >> u >> v >> c;",
      "    u--; v--;",
      "    G[u].emplace_back(Edge(v,c)); // u→vにcの辺を張る(v<=u+cを表現)",
      "  }",
      "  vi dist=bellman_ford(G,0); // 頂点0を始点とする各頂点への距離",
      "  ",
      "  // 負閉路を持つ場合はそのような関係は存在しない,dist[N-1]==INFの場合は無限に離れられる",
      "  ",
      "  // 最大距離を求める",
      "  fo(dist[N]);",
      "  ",
      "  // 隣の頂点との距離を求める",
      "  // vi ans(N-1);",
      "  // rep(i,0,N-1) ans[i]=dist[i+1]-dist[i];",
      "  // out_vec_with_space(ans);",
      "}"
    ],
    "description": "牛ゲー2(負辺あり)"
  },
  "modinv": {
    "prefix": "modinv",
    "body": [
// 拡張 Euclid の互除法(modinvにこれも必要)
// ax+by=gcd(a,b)となるx,yを求める,戻り値はgcd(a,b)
int extgcd(int a, int b, int &x, int &y){
  if(b==0){ x = 1; y = 0; return a; }
  int g=extgcd(b, a%b, y, x);
  y-=a/b*x;
  return g;
}
// 任意mod上の逆元を求める
// 逆元の存在条件はaとmが互いに素である事
int modinv(int a, int m){
  int x, y;
  extgcd(a, m, x, y);
  x %= m;
  if(x < 0) x += m;
  return x;
}
// 使用例
// 3(mod5)の逆元を求める
// int inv=modinv(3,5);
    ],
    "description": "任意mod上の逆元"
  },
  "Rerooting": {
    "prefix": "Rerooting",
    "body": [
      "template <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int), V (*put_vertex)(E, int)>",
      "struct RerootingDP {",
      "  struct edge {",
      "    int to, idx, xdi;",
      "  };",
      "  RerootingDP(int n_ = 0) : n(n_), inner_edge_id(0) {",
      "    es.resize(2*n-2);",
      "    start.resize(2*n-2);",
      "    if (n == 1) es_build();",
      "  }",
      "  void add_edge(int u, int v, int idx, int xdi){",
      "    start[inner_edge_id] = u;",
      "    es[inner_edge_id] = {v,idx,xdi};",
      "    inner_edge_id++;",
      "    start[inner_edge_id] = v;",
      "    es[inner_edge_id] = {u,xdi,idx};",
      "    inner_edge_id++;",
      "    if (inner_edge_id == 2*n-2){",
      "      es_build();",
      "    }",
      "  }",
      "  vector<V> build(int root_ = 0){",
      "    root = root_;",
      "    vector<V> subdp(n); subdp[0] = put_vertex(e(),0);",
      "    outs.resize(n);",
      "    vector<int> geta(n+1,0);",
      "    rep(i,0,n) geta[i+1] = start[i+1] - start[i] - 1;",
      "    geta[root+1]++;",
      "    rep(i,0,n) geta[i+1] += geta[i];",
      "    auto dfs = [&](auto sfs, int v, int f) -> void {",
      "      E val = e();",
      "      rep(i,start[v],start[v+1]){",
      "        if (es[i].to == f){",
      "          swap(es[start[v+1]-1],es[i]);",
      "        }",
      "        if (es[i].to == f) continue;",
      "        sfs(sfs,es[i].to,v);",
      "        E nval = put_edge(subdp[es[i].to],es[i].idx);",
      "        outs[geta[v]++] = nval;",
      "        val = merge(val,nval);",
      "      }",
      "      subdp[v] = put_vertex(val, v);",
      "    };",
      "    dfs(dfs,root,-1);",
      "    return subdp;",
      "  }",
      "  vector<V> reroot(){",
      "    vector<E> reverse_edge(n);",
      "    reverse_edge[root] = e();",
      "    vector<V> answers(n);",
      "    auto dfs = [&](auto sfs, int v) -> void {",
      "      int le = outs_start(v);",
      "      int ri = outs_start(v+1);",
      "      int siz = ri - le;",
      "      vector<E> rui(siz+1);",
      "      rui[siz] = e();",
      "      for(int i = siz-1; i >= 0; i--){",
      "        rui[i] = merge(outs[le+i],rui[i+1]);",
      "      }",
      "      answers[v] = put_vertex(merge(rui[0],reverse_edge[v]),v);",
      "      E lui = e();",
      "      rep(i,0,siz){",
      "        V rdp = put_vertex(merge(merge(lui,rui[i+1]),reverse_edge[v]),v);",
      "        reverse_edge[es[start[v]+i].to] = put_edge(rdp,es[start[v]+i].xdi);",
      "        lui = merge(lui,outs[le+i]);",
      "        sfs(sfs,es[start[v]+i].to);",
      "      }",
      "    };",
      "    dfs(dfs,root);",
      "    return answers;",
      "  }",
      "  private:",
      "  int n, root, inner_edge_id;",
      "  vector<E> outs;",
      "  vector<edge> es;",
      "  vector<int> start;",
      "  int outs_start(int v){",
      "    int res = start[v] - v;",
      "    if (root < v) res++;",
      "    return res;",
      "  }",
      "  void es_build(){",
      "    vector<edge> nes(2*n-2);",
      "    vector<int> nstart(n+2,0);",
      "    rep(i,0,2*n-2) nstart[start[i]+2]++;",
      "    rep(i,0,n) nstart[i+1] += nstart[i];",
      "    rep(i,0,2*n-2) nes[nstart[start[i]+1]++] = es[i];",
      "    swap(es,nes);",
      "    swap(start,nstart);",
      "  }",
      "};",
      "",
      "using E=int; // 可換モノイドの型",
      "using V=int; // dpの値の型",
      "// 部分木を束ねる処理",
      "E merge(E a, E b){",
      "  return (a * b);",
      "}",
      "// Eの単位元",
      "E e(){",
      "  return 1;",
      "}",
      "// 辺番号iの辺を付加する関数",
      "E put_edge(V v, int i){",
      "  return (v + 1);",
      "}",
      "// 頂点番号vの頂点を付加する関数",
      "V put_vertex(E e, int v){",
      "  return e;",
      "}",
    ],
    "description": "全方位木DP"
  },
  "Rerooting-use": {
    "prefix": "RerootingUse",
    "body": [
      "int N;",
      "cin >> N;",
      "RerootingDP<E,V,merge,e,put_edge,put_vertex> G(N);",
      "rep(i,0,N-1){",
      "  int u, v; cin >> u >> v;",
      "  G.add_edge(u-1,v-1,i,i);",
      "}",
      "G.build();",
      "vi ans=G.reroot();",
      "rep(i,0,N) fo(ans[i]);",
    ],
    "description": "全方位木DPの使い方"
  },
  "Merge_teku": {
    "prefix": "merge_teku",
    "body": [
void merge_teku(vi &from, vi &to){
  if(sz(from)<sz(to)){
    fore(e,from) to.emplace_back(e);
  }else{
    fore(e,to) from.emplace_back(e);
    swap(from,to);
  }
  from={};
}
    ],
    "description": "マージテク"
  },

  // "Proc_brackets"
  // "prefix": "proc_brackets",
  // "description": "括弧列を処理する"
  // 括弧列を処理する関数,P(正しい括弧ペアの個数,残った個数)を返す
  P proc_brackets(string S){
    int ok_p_num=0; // 正しい括弧ペアの個数
    int N=sz(S);
    stack<char> st;
    rep(i,0,N){
      char cu=S[i];
      // 未処理のものが空の場合
      if(sz(st)==0){
        st.push(cu);
        continue;
      }
      char pre=st.top();
      // 正しい括弧ペアの処理
      if(pre=='(' and cu==')'){
        st.pop();
        ok_p_num++;
      }else{
        st.push(cu);
      }
    }
    return P(ok_p_num,sz(st));
  }
  // 使い方
  int ok_p_num,ng_num;
  tie(ok_p_num,ng_num)=proc_brackets(S);

// "ZobristHash"==================================================
// "prefix": "ZobristHash",
// "description": "ZobristHash"
using ull = unsigned long long;
mt19937_64 rng(42);
const ll mod = (1LL<<61) - 1; // 素数
// Zobrist Hashクラス(2箇所変える)
class ZobristHash {
private:
  unordered_map<int, ull> zobristTable;  // 数値ごとのランダムなハッシュ値
public:
  ZobristHash() {

  }

  uint64_t getHash(int value) {
    // まだ割り当てていない場合はランダムなハッシュ値を生成
    if(zobristTable.find(value) == zobristTable.end()) {
      zobristTable[value] = rng()%mod;
    }
    return zobristTable[value];
  }
};

// 数列に対してZobrist Hashの累積ハッシュを計算する
vector<uint64_t> computeCumulativeHash(const vi& v, ZobristHash& zh) {
  vector<uint64_t> cumulativeHash(sz(v)+1, 0);

  // 集合(始点固定,終点自由)(未検証)
  // unordered_set<int> used;
  // rep(i,0,sz(v)){
  //   if(!used.count(v[i])){
  //     cumulativeHash[i + 1] = cumulativeHash[i] ^ zh.getHash(v[i]);
  //     used.insert(v[i]); // この要素を1度だけハッシュに反映
  //   }else{
  //     cumulativeHash[i + 1] = cumulativeHash[i]; // すでに反映済みならハッシュをそのまま
  //   }
  // }

  // 要素の偶奇(始点自由,終点自由)(未検証)
  // rep(i,0,sz(v)) cumulativeHash[i + 1] = cumulativeHash[i];

  // 要素の多重集合(始点自由,終点自由)(検証済)
  rep(i,0,sz(v)) cumulativeHash[i + 1] = (cumulativeHash[i] + zh.getHash(v[i]))%mod;

  return cumulativeHash;
}

// 区間[l, r]のハッシュ値を取得
uint64_t getRangeHash(const vector<uint64_t>& cumulativeHash, int l, int r) {
  // 集合(始点固定,終点自由)
  // return cumulativeHash[r]; // lは使わないのでl=0等を適当に渡せばよい

  // 要素の偶奇(始点自由,終点自由)
  // return cumulativeHash[r] ^ cumulativeHash[l];

  // 要素の多重集合(始点自由,終点自由)
  return (cumulativeHash[r] - cumulativeHash[l] + mod) % mod;
}

// "ZobristHash-use"==================================================
// "prefix": "ZobristHashUse",
// "description": "ZobristHashの使い方(ABC367F)"
int N,Q;
cin >> N >> Q;
vi A(N),B(N);
rep(i,0,N) cin >> A[i];
rep(i,0,N) cin >> B[i];

// Zobrist Hashの初期化
ZobristHash zh;

// AとBに対する累積ハッシュを計算
vector<uint64_t> hashA = computeCumulativeHash(A, zh);
vector<uint64_t> hashB = computeCumulativeHash(B, zh);

// クエリの処理
while(Q--) {
  int l, r, L, R;
  cin >> l >> r >> L >> R;
  --l; --L;  // 0-indexに合わせる
  
  // Aの区間[l, r]のハッシュとBの区間[L, R]のハッシュを比較
  uint64_t hashA_segment = getRangeHash(hashA, l, r);
  uint64_t hashB_segment = getRangeHash(hashB, L, R);
  
  if (hashA_segment == hashB_segment) fo("Yes");
  else fo("No");
}

// "Trie"==================================================
// "prefix": "Trie",
// "description": "Trie木"
class TrieNode {
public:
  bool isEndOfWord;
  int wordCount;      // 単語の出現回数
  int prefixCount;    // プレフィックスの出現回数
  int prefixAfterLen;    // プレフィックスの後の最小文字数
  unordered_map<char, TrieNode*> children;

  TrieNode() : isEndOfWord(false), wordCount(0), prefixCount(0), prefixAfterLen(INF) {}
};

class Trie {
private:
  TrieNode* root;

public:
  Trie() {
    root = new TrieNode();
  }

  // 単語を挿入する関数
  void insert(const string& word) {
    TrieNode* node = root;
    rep(i,0,sz(word)){
    char c = word[i];
      if (node->children.find(c) == node->children.end()) {
        node->children[c] = new TrieNode();
      }
      node = node->children[c];
      node->prefixCount += 1; // プレフィックスの出現回数をインクリメント
      chmin(node->prefixAfterLen,sz(word)-i-1); // プレフィックスの後に続く文字数を更新
    }
    node->isEndOfWord = true;
    node->wordCount += 1; // 単語の出現回数をインクリメント
  }

  // 単語を検索し、出現回数を返す関数
  int search(const string& word) const {
    TrieNode* node = root;
    for (char c : word) {
      if (node->children.find(c) == node->children.end()) {
        return 0; // 単語が存在しない場合は0を返す
      }
      node = node->children[c];
    }
    return node->isEndOfWord ? node->wordCount : 0;
  }

  // プレフィックスの出現回数を返す関数
  int countPrefix(const string& prefix) const {
    TrieNode* node = root;
    for (char c : prefix) {
      if (node->children.find(c) == node->children.end()) {
        return 0; // プレフィックスが存在しない場合は0を返す
      }
      node = node->children[c];
    }
    return node->prefixCount;
  }

  // 各プレフィックスの出現回数をvectorで返す関数(ABC377G)
  vector<int> getPrefixCounts(const string& word) const {
    vector<int> prefixCounts;
    TrieNode* node = root;
    for (char c : word) {
      if (node->children.find(c) == node->children.end()) {
        break; // プレフィックスが存在しなくなったら終了
      }
      node = node->children[c];
      prefixCounts.push_back(node->prefixCount); // 現在のプレフィックスの出現回数を追加
    }
    return prefixCounts;
  }

  // 各プレフィックスの後に続く最小文字数をvectorで返す関数
  vector<int> getPrefixAfterLen(const string& word) const {
    vector<int> prefixAfterLens;
    TrieNode* node = root;
    for (char c : word) {
      if (node->children.find(c) == node->children.end()) {
        break; // プレフィックスが存在しなくなったら終了
      }
      node = node->children[c];
      prefixAfterLens.push_back(node->prefixAfterLen); // 現在のプレフィックスの出現回数を追加
    }
    return prefixAfterLens;
  }
};

// "Trie-use"==================================================
// "prefix": "TrieUse",
// "description": "Trie木の使い方"
// 構築
Trie trie;
// 挿入:O(n)
trie.insert("apple");
trie.insert("apple");
trie.insert("apricot");
// 単語の出現回数:O(n)
int a=trie.search("apple"); // 2
int b=trie.search("apricot"); // 1
int c=trie.search("banana"); // 0
// プレフィックスの出現回数:O(n)
int d=trie.countPrefix("ap"); // 3
// 先頭から切り出した全プレフィックスの出現回数:O(n)
vi e=trie.getPrefixCounts("apple"); // {3,3,2,2,2}
// 先頭から切り出した全プレフィックスの後に続く文字数
vi f=trie.getPrefixAfterLen("appear"); // {4,3,2}
