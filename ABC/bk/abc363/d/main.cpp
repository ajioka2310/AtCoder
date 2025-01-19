// abc363 D - Palindromic Number
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
  unsigned long long N; cin>>N;
  // 桁を確定させる
  int digit = 0;
  unsigned long long now = 0;
  unsigned long long next = 0;
  while(true){
    digit++;
    if (digit==1) next = now + 10;
    else if (digit==2) next = now + 9;
    else {
      unsigned long long tmp = 9;
      rep(i,(digit+1)/2-1) tmp *=10;
      next = now + tmp;
    }
    if (next>=N) break;
    now = next;
  }
  dump(digit,now,next,N);
  // digit桁のN-now番目を調べる
  N -= now;
  dump(digit,now,next,N);

  v1i32 ls;
  if (digit==1){
    cout << N-1 << endl;
    return 0;
  }
  else if (digit==2){
    cout << N << N << endl;
    return 0;
  }
  else{
    unsigned long long tmp = 1;
    int cnt = 0;
    rep(i,(digit+1)/2-1) {tmp *= 10; cnt++;}
    dump(cnt);
    rep(i,(digit+1)/2){
      if (i==0){
        ls.push_back((N-1)/tmp+1);
        N -= (N-1)/tmp * tmp;
        tmp /= 10;
      }
      else{
        ls.push_back((N-1)/tmp);
        N -= ls[i]*tmp;
        tmp /= 10;
      }
      dump(N,tmp);
    }
  }
  dump(ls);

  rep(i,digit/2){
    cout << ls[i];
  }
  if (digit%2==1){
    cout << ls[digit/2];
  }
  rrep(i,digit/2){
    cout << ls[i] ;
  }
  cout << endl;
}
//118260671090469809
// ->8260671090469810
//   10000000000000000
// 8260671090469810
//1826067109046980990896409017606281
//1826067109046980990896409017606281
