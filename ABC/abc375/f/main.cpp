// abc375 F - Road Blocked
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

constexpr i64 INF = (1LL << 60);
const int MOD=1e9+7;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

bool cmp(pair_int a, pair_int b) { return a.second < b.second; }


int main(){
  int N,M,Q; cin>>N>>M>>Q;
  v2i64 base(N,v1i64(N,INF));rep(i,N) base[i][i] = 0;
  v2i64 ls(M,v1i64(3,0));
  
  rep(i,M){
    i64 A,B,C; cin>>A>>B>>C;
    A--;B--;
    base[A][B] = C;
    base[B][A] = C;
    ls[i] = {A,B,C};
  }

  v2i64 query(Q);
  rep(q,Q){
    int type; cin>>type;
    if(type==1){
      int i; cin>>i;
      query[q].push_back(type);
      query[q].push_back(i-1);
      i64 A = ls[i-1][0];
      i64 B = ls[i-1][1];
      base[A][B] = INF;
      base[B][A] = INF;
    }
    else{
      int x,y; cin>>x>>y;
      query[q].push_back(type);
      query[q].push_back(x-1);
      query[q].push_back(y-1);
    }
  }

  // init
  rep(k,N)rep(i,N)rep(j,N){
    base[i][j] = min(base[i][j],base[i][k]+base[k][j]);
  }
  v1i64 res;
  rep(q,Q){
    if (query[Q-1-q][0]==1){
      int idx = query[Q-1-q][1];
      i64 A = ls[idx][0];
      i64 B = ls[idx][1];
      i64 C = ls[idx][2];
      base[A][B] = C;
      base[B][A] = C;
      rep(i,N)rep(j,N){
        base[i][j] = min(base[i][j],base[i][A]+base[A][B]+base[B][j]);
        base[i][j] = min(base[i][j],base[i][B]+base[B][A]+base[A][j]);
      }
    }
    else{
      int st = query[Q-1-q][1];
      int ed = query[Q-1-q][2];
      if (base[st][ed]==INF){
        res.push_back(-1);
      }
      else{
        res.push_back(base[st][ed]);
      }
    }
  }
  rep(i,res.size()){
    cout << res[res.size()-1-i] << endl;
  }


}
