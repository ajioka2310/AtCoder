// abc362 D - Shortest Path 3
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


struct Edge{
    int to;
    int cost;
};
using Graph = vector<vector<Edge>>;
using Pair = pair<i64,int>;

// ダイクストラ
void Dijkstra(const Graph& graph, v1i64& distances, int startIndex, v1i64& path){
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
    int N,M; cin>>N>>M;
    v1i64 A(N,0); rep(i,N) cin>>A[i];
    v1i64 distances(N,INF);
    v1i64 path(N,-1);
    Graph graph(N);
    dump(graph);
    dump(N,M);

    rep(i,M){
        i64 U,V,B; cin>>U>>V>>B;
        U--;V--;
        dump(U,V);
        graph[U].push_back({V,B+A[V]});
        graph[V].push_back({U,B+A[U]});
    }
    Dijkstra(graph,distances,0,path);
    dump(path);

    dump(distances);
    krep(i,1,distances.size()-1){
        cout << distances[i]+A[0] << " ";
    }
    cout << distances[distances.size()-1]+A[0] << endl;
    
}

