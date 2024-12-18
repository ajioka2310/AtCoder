// abc322 D - Polyomino
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

v2i64 dfs(v2i64 pori, i64 r){
  v2i64 out(4,v1i64(4,0));
  if (r==0) return pori;
  else{
    rep(i,4)rep(j,4){
      out[i][j] = pori[3-j][i];
    }
    return dfs(out,r-1);
  }
}
i64 func(v2i64 ls, i64 h, i64 w){
  if (0<=h&&h<=3&&0<=w&&w<=3) return ls[h][w];
  else return 0;
}

int main(){
  v3i64 poris(3,v2i64(4,v1i64(4,0)));
  i64 cnt = 0;
  rep(i,3)rep(j,4){
    string P; cin>>P;
    dump(P);
    rep(k,4){
      if (P[k]=='#'){
        cnt++;
        poris[i][j][k] = 1;
      }
    }
  };
  if (cnt!=16){
    cout << "No" << endl;
    return 0;
  }
  
  rep(r0,4)rep(r1,4)rep(r2,4){
    v2i64 p0 = dfs(poris[0],r0);
    v2i64 p1 = dfs(poris[1],r1);
    v2i64 p2 = dfs(poris[2],r2);
    vector<pair<i64,i64>> H(3,{3,0});
    vector<pair<i64,i64>> W(3,{3,0});
    // krep(h0,-3,4)krep(h1,-3,4)krep(h2,-3,4)krep(w0,-3,4)krep(w1,-3,4)krep(w2,-3,4){
    //   bool flg = true;
    //   rep(i,4)rep(j,4){
    //     if(func(p0,i-h0,j-w0)+func(p1,i-h1,j-w1)+func(p2,i-h2,j-w2)!=1) flg = false;
    //   }
    //   if (flg){
    //     cout << "Yes" << endl;
    //     return 0;
    //   }
    // }
    rep(i,4)rep(j,4){
      if (p0[i][j]==1){
        chmin(H[0].first,1LL*i);
        chmax(H[0].second,1LL*i);
        chmin(W[0].first,1LL*j);
        chmax(W[0].second,1LL*j);
      }
      if (p1[i][j]==1){
        chmin(H[1].first,1LL*i);
        chmax(H[1].second,1LL*i);
        chmin(W[1].first,1LL*j);
        chmax(W[1].second,1LL*j);
      }
      if (p2[i][j]==1){
        chmin(H[2].first,1LL*i);
        chmax(H[2].second,1LL*i);
        chmin(W[2].first,1LL*j);
        chmax(W[2].second,1LL*j);
      }
    }
    rep(i,3){
      H[i].first = H[i].first+1;
      H[i].second = H[i].second-3;
      W[i].first = W[i].first+1;
      W[i].second = W[i].second-3;
    }
    if (r0==1&&r1==0&&r2==1){
      dump(p0,p1,p2);
      dump(H,W);
    }
    krep(h0,H[0].second,H[0].first)krep(h1,H[1].second,H[1].first)krep(h2,H[2].second,H[2].first){
      krep(w0,W[0].second,W[0].first)krep(w1,W[1].second,W[1].first)krep(w2,W[2].second,W[2].first){
        // if (r0==1&&r1==0&&r2==1){
        //   dump(h0,h1,h2);
        //   dump(w0,w1,w2);
        // }
        bool tmp_flg = true;
        rep(i,4)rep(j,4){
          if (r0==1&&r1==0&&r2==1&&h0==0&&h1==1&&h2==-1&&w0==-1&&w1==1&&w2==0){
            dump(func(p0,i+h0,j+w0)+func(p1,i+h1,j+w1)+func(p2,i+h2,j+w2));
          }
          if (func(p0,i+h0,j+w0)+func(p1,i+h1,j+w1)+func(p2,i+h2,j+w2)!=1) tmp_flg = false;
        }
        if (tmp_flg){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }

  }
  cout << "No" << endl;

}
