// abc193 D - Poker
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
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};

constexpr i64 INF = (1LL << 60);
const int MOD=1e9+7;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

bool cmp(pair_int a, pair_int b) { return a.second < b.second; }

bool check(string S, string T){
  int A = 0, B = 0;
  krep(i,1,10){
    int cnt = 0;
    rep(j,5) if (S[j]-'0'==i) cnt++;
    int now = i;
    rep(j,cnt) now *= 10;
    A += now;

    cnt = 0;
    rep(j,5) if (T[j]-'0'==i) cnt++;
    now = i;
    rep(j,cnt) now *= 10;
    B += now;
  }
  return A > B;
}

int main(){
  int K; cin >> K;
  string S; cin >> S;
  string T; cin >> T;
  map<int,int>dict;
  krep(i,1,10) dict[i] = K;
  rep(i,4){
    dict[S[i]-'0']--;
    dict[T[i]-'0']--;
  }

  i64 base = 0;
  i64 win = 0;
  krep(i,1,10)krep(j,1,10){
    if (i==j){
      if (dict[i]>=2){
        base += 1LL*dict[i]*(dict[i]-1);
        S[4] = to_string(i)[0];
        T[4] = to_string(j)[0];
        if (check(S,T)) win += 1LL*dict[i]*(dict[i]-1);
      }
    }
    else{
      if (dict[i]>=1&&dict[j]>=1){
        base += 1LL*dict[i]*dict[j];
        S[4] = to_string(i)[0];
        T[4] = to_string(j)[0];
        if (check(S,T)) win += 1LL*dict[i]*dict[j];
      }
    }
    dump(S,T);
    dump(check(S,T));
    dump(base,win);
  }


  double res = 1.0*win/base;
  cout << fixed << setprecision(16);
  cout << res << endl;

}
