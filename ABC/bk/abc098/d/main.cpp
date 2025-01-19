// abc098 D - Xor Sum 2
#ifdef DEFINED_ONLY_IN_LOCAL
#include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// <次のセクションの内容はここに追加する>
#define dump(...) cpp_dump(__VA_ARGS__)
namespace cp = cpp_dump;
CPP_DUMP_SET_OPTION_GLOBAL(max_line_width, 80);
CPP_DUMP_SET_OPTION_GLOBAL(log_label_func, cp::log_label::filename());
CPP_DUMP_SET_OPTION_GLOBAL(enable_asterisk, true);
#else
#define dump(...)
#define CPP_DUMP_SET_OPTION(...)
#define CPP_DUMP_SET_OPTION_GLOBAL(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)
#endif

#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using i64 = long long;
using f80 = long double;
using v1i32 = vector<int>;
using v1i64 = vector<i64>;
using v1str = vector<string>;
using v2i32 = vector<v1i32>;
using v2i64 = vector<v1i64>;
using v2str = vector<v1str>;
using v3i32 = vector<v2i32>;
using v3i64 = vector<v2i64>;
using pair_int = pair<int,int>;

#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define rrep(i,n) for (int i= int(n)-1; i >=0; --i)
#define reps(i,n) for (int i = 1; i <= int(n); ++i)
#define rreps(i,n) for (int i = int(n); i >= 1; --i)
#define repc(i,n) for (int i = 0; i <= int(n); ++i)
#define rrepc(i,n) for (int i = int(n); i >= 0; --i)

#define krep(i,k,n) for (int i = k; i < (int)(n); ++i)
#define rkrep(i,start,end) for (int i=start-1; i >=end; --i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define each(x,y) for (auto &x:y)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define max_idx(a) max_element(all(a)) - a.begin()
#define min_idx(a) min_element(all(a)) - a.begin()
#define max_value(A) A[max_idx(A)]
#define min_value(A) A[min_idx(A)]
#define sum_values(A) reduce(all(A))

template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};

const int INF=INT32_MAX/2;
const int MOD=1e9+7;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

int main(){
  dump(2^5^3^6);
  dump(2^5^3^6^2^5);

  dump(3^6);
  int N; cin>>N;
  v1i64 A(N,0); rep(i,N) cin>>A[i];
  v1i64 A_CUM(N,A[0]); krep(i,1,N) A_CUM[i] = A_CUM[i-1]+A[i];
  v1i64 A_XOR(N,A[0]); krep(i,1,N) A_XOR[i] = A_XOR[i-1]^A[i];
  i64 ans = 0;
  rep(l,N){
    int ok = l, ng = N;
    while(ng-ok>1){
      int mid = (ok+ng)/2;
      i64 x = A_XOR[mid];
      i64 s = A_CUM[mid];
      if (l) x ^= A_XOR[l-1];
      if (l) s -= A_CUM[l-1];
      if (x==s) ok = mid;
      else ng = mid;
    }
    ans += ok - l + 1;
  }
  cout << ans << endl;
  


}

// void _main() {
//     cin >> N;
//     rep(i, 0, N) cin >> A[i];
 
//     rep(i, 0, N) xo[i] = sm[i] = A[i];
//     rep(i, 1, N) xo[i] ^= xo[i - 1];
//     rep(i, 1, N) sm[i] += sm[i - 1];
 
//     ll ans = 0;
//     rep(l, 0, N) {
//         int ok = l, ng = N;
//         while (ok + 1 != ng) {
//             int md = (ok + ng) / 2;
 
//             ll x = xo[md];
//             if (l) x ^= xo[l - 1];
 
//             ll s = sm[md];
//             if (l) s -= sm[l - 1];
 
//             if (x == s) ok = md;
//             else ng = md;
//         }
 
//         ans += ok - l + 1;
//     }
//     cout << ans << endl;
// }