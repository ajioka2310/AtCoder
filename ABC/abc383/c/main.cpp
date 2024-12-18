// abc383 C - Humidifier 3
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
using pair_i64 = pair<i64,i64>;


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

v2i64 graph(1001,v1i64(1001,0));
v2i64 dist(1001,v1i64(1001,INF));

int main(){
  i64 H,W,D; cin>>H>>W>>D;
  rep(h,H)rep(w,W){
    char a; cin>>a;
    if (a=='#') {
      graph[h][w] = 1;
    }
    else if (a=='H') {
      graph[h][w] = 2;
      dist[h][w] = 0;
    }
  }

  rep(h,H)rep(w,W){
    if (graph[h][w]!=2) continue;
    deque<pair<int,pair_i64>> que;
    que.push_back({0,{h,w}});
    while (!que.empty()){
      auto [_dist,idx] = que.front();que.pop_front();
      if (1<=idx.first){
        if (_dist+1<=D&&_dist+1<dist[idx.first-1][idx.second]&&graph[idx.first-1][idx.second]==0){
          que.push_back({_dist+1,{idx.first-1,idx.second}});
          dist[idx.first-1][idx.second] = _dist+1;
        }
      }
      if (idx.first<=H-2){
        if (_dist+1<=D&&_dist+1<dist[idx.first+1][idx.second]&&graph[idx.first+1][idx.second]==0){
          que.push_back({_dist+1,{idx.first+1,idx.second}});
          dist[idx.first+1][idx.second] = _dist+1;
        }
      }
      if (1<=idx.second){
        if (_dist+1<=D&&_dist+1<dist[idx.first][idx.second-1]&&graph[idx.first][idx.second-1]==0){
          que.push_back({_dist+1,{idx.first,idx.second-1}});
          dist[idx.first][idx.second-1] = _dist+1;
        }
      }
      if (idx.second<=W-2){
        if (_dist+1<=D&&_dist+1<dist[idx.first][idx.second+1]&&graph[idx.first][idx.second+1]==0){
          que.push_back({_dist+1,{idx.first,idx.second+1}});
          dist[idx.first][idx.second+1] = _dist+1;
        }
      }
    }
  }

  i64 res = 0;
  rep(h,H)rep(w,W){
    if (dist[h][w]<=D) res++;
  }
  cout << res << endl;
  
  
}
