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

using namespace std;

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
#define max_idx(a) max_element(all(a)) - a.begin();
#define min_idx(a) min_element(all(a)) - a.begin();

const int INF=INT32_MAX/2;
const int MOD=10007;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

vec seen;

void dfs(const Graph &G, vec &seen,int node){
  for (auto next_v: G[node]){
    if (seen[next_v]>0) continue;
    seen[next_v] = seen[node]+1;
    dfs(G, seen, next_v);
  }
}


int main(){
  int N; cin>>N;
  seen.assign(N,0);
  Graph graph(N);
  rep(i,N-1){
    int A,B; cin>>A>>B;
    graph[A-1].push_back(B-1);
    graph[B-1].push_back(A-1);

  }
  dump(graph);
  seen[0] = 1;
  dfs(graph,seen,0);
  dump(seen);

  int idx_max = max_idx(seen);

  rep(i,N) seen[i] = 0;

  dfs(graph,seen,idx_max);
  dump(seen);

  idx_max = max_idx(seen);

  cout << seen[idx_max]+1 << endl;

}
