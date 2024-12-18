// abc046 B - Painting Balls with AtCoDeer
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


/////////////////////////////////////////////////////////////

struct Edge{
    i64 to;
    i64 cost;
};
using Graph = vector<vector<Edge>>;
using Pair = pair<i64,i64>;

// ダイクストラ
void Dijkstra(const Graph& graph, v1i64& distances, i64 startIndex, v1i64& path){
    pqasc<Pair> q;
    distances[startIndex] = 0;
    q.emplace((distances[startIndex]),startIndex);
    while(!q.empty()){
        // 探索ポイントの取り出し
        i64 distance = q.top().first;
        int from = q.top().second;
        q.pop();
        // 最短距離のみ処理（枝刈）
        if (distances[from]<distance) continue;
        // 現在ノードから
        for (const auto& edge: graph[from]){
            i64 new_d = (distances[from]+edge.cost);
            // 最短距離であれば更新
            if (new_d < distances[edge.to]){
                distances[edge.to] = new_d;
                path[edge.to] = from;
                q.emplace(distances[edge.to],edge.to);
            }
        }

    }
}

int main(){
  i64 V = 4;
  i64 E = 6;
  i64 r = 3;
  Graph graph = {
    {{1,1},{2,4}},//0
    {{2,2}},//1
    {{0,1}},//2
    {{1,1},{2,5}},//3
  };
  v1i64 distances(V,INF);
  v1i64 path(V,-1);
  Dijkstra(graph,distances,r,path);
  dump(path);
  dump(distances);
}
