// abc182 E - Akari
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


int main(){
  // 縦と横に分けて考える。
  int H,W,N,M; cin>>H>>W>>N>>M;
  v2i32 base(H,v1i32(W,0));
  v1i32 A(N,0),B(N,0);
  rep(i,N) {cin >> A[i] >> B[i]; A[i]--,B[i]--;}
  v1i32 C(M,0),D(M,0);
  rep(i,M) {cin >> C[i] >> D[i]; C[i]--,D[i]--;}

  rep(i,M){
    base[C[i]][D[i]] = 1;
  }
  
  set<pair_int> res;
  // tate
  v2i32 tate = base;
  rep(i,N){
    int y = A[i];
    int x = B[i];
    tate[y][x] = 1;
    res.insert({y,x});
    while(y>0){
      y--;
      if (tate[y][x]==1) break;
      else {
        tate[y][x] = 1;
        res.insert({y,x});
      }
    }
    y = A[i];
    x = B[i];
    while(y<H-1){
      y++;
      if (tate[y][x]==1) break;
      else {
        tate[y][x] = 1;
        res.insert({y,x});
      }
    }
  }
  dump(tate);
  // yoko
  v2i32 yoko = base;
  rep(i,N){
    int y = A[i];
    int x = B[i];
    yoko[y][x] = 1;
    res.insert({y,x});
    while(x>0){
      x--;
      if (yoko[y][x]==1) break;
      else {
        yoko[y][x] = 1;
        res.insert({y,x});
      }
    }
    y = A[i];
    x = B[i];
    while(x<W-1){
      x++;
      if (yoko[y][x]==1) break;
      else {
        yoko[y][x] = 1;
        res.insert({y,x});
      }
    }
  }
  dump(yoko);
  cout << res.size() << endl;
}