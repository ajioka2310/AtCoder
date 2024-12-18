// abc384 E - Takahashi is Slime 2
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
  i64 H,W,X; cin>>H>>W>>X;
  i64 P,Q; cin>>P>>Q;
  P--;Q--;
  v2i64 ls(H,v1i64(W,0));
  rep(i,H)rep(j,W){
    cin>>ls[i][j];
  }
  v2i64 check(H,v1i64(W,0));
  check[P][Q] = 1;
  i64 now = ls[P][Q];
  pqasc<pair<i64,pair<i64,i64>>> que;
  if (P>0){
    que.push({ls[P-1][Q],{P-1,Q}});
    check[P-1][Q] = 1;
  } 
  if (P<H-1){
    que.push({ls[P+1][Q],{P+1,Q}});
    check[P+1][Q] = 1;
  } 
  if (Q>0){
    que.push({ls[P][Q-1],{P,Q-1}});
    check[P][Q-1] = 1;
  } 
  if (Q<W-1){
    que.push({ls[P][Q+1],{P,Q+1}});
    check[P][Q+1] = 1;
  } 
  dump(check);
  while(!que.empty()){
    pair<i64,pair<i64,i64>> tmp = que.top();
    i64 next = tmp.first;
    pair<i64,i64> idx = tmp.second;
    que.pop();
    dump(now,next,idx);
    // cout <<  << endl;
    
    if (next>=double(now)/X){
      break;
    }
    else{
      now += next;
      if (idx.first>0){
        if (check[idx.first-1][idx.second]==0){
          que.push({ls[idx.first-1][idx.second],{idx.first-1,idx.second}});
          check[idx.first-1][idx.second] = 1;
        }
      }
      if (idx.first<H-1){
        if (check[idx.first+1][idx.second]==0){
          que.push({ls[idx.first+1][idx.second],{idx.first+1,idx.second}});
          check[idx.first+1][idx.second] = 1;
        }
      }
      if (idx.second>0){
        if (check[idx.first][idx.second-1]==0){
          que.push({ls[idx.first][idx.second-1],{idx.first,idx.second-1}});
          check[idx.first][idx.second-1] = 1;
        }
      }
      if (idx.second<W-1){
        if (check[idx.first][idx.second+1]==0){
          que.push({ls[idx.first][idx.second+1],{idx.first,idx.second+1}});
          check[idx.first][idx.second+1] = 1;
        }
      }  
    }
    dump(check);

  }
  cout << now << endl;
  



  
  
}
