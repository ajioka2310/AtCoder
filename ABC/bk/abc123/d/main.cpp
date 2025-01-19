// abc123 D - Cake 123
// abc126 E - 1 or 2
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

#define ll long long
#define vec vector<int>
#define llvec vector<long long>
#define Graph vector<vector<int>>
#define llGraph vector<vector<ll>>
#define pair_int pair<int,int>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define rep_auto(i,A) for (auto& i:A)
#define all(a) (a).begin(), (a).end()
#define all_inv(a) (a).rbegin(), (a).rend()
#define max_idx(a) max_element(all(a)) - a.begin()
#define min_idx(a) min_element(all(a)) - a.begin()
#define max_value(A) A[max_idx(A)]
#define min_value(A) A[min_idx(A)]


const int INF=INT32_MAX/2;
const int MOD=10007;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

int main(){
  llvec N(3,0); rep(i,3) cin>>N[i];  
  int K;cin>>K;

  llGraph v(3);
  rep(i,3){
    v[i].resize(N[i]);
    rep(j,N[i]){
      cin>>v[i][j];
    }
    sort(all(v[i]),greater<ll>());
  }

  priority_queue<pair<ll,vector<int>>> que;
  set<pair<ll,vector<int>>> se;

  que.push({v[0][0]+v[1][0]+v[2][0],{0,0,0}});

  dump(que);

  rep(k,K){
    auto c = que.top();que.pop();
    cout << c.first << endl;

    rep(i,3){
      if (c.second[i]+1<N[i]){
        ll sum = c.first - v[i][c.second[i]] + v[i][c.second[i]+1];
        auto num = c.second; num[i]++;
        pair<ll,vector<int>> d = {sum,num};
        if (!se.count(d)){
          se.insert(d),que.push(d);
        }
      }

    }
  }





}
