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
#define rrep(i,start) for (int i=start-1; i >=0; --i)
#define krep(i,k,n) for (int i = k; i < (int)(n); ++i)
#define rkrep(i,start,end) for (int i=start-1; i >=end; --i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define rep_auto(i,A) for (auto& i:A)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define max_idx(a) max_element(all(a)) - a.begin()
#define min_idx(a) min_element(all(a)) - a.begin()
#define max_value(A) A[max_idx(A)]
#define min_value(A) A[min_idx(A)]
#define sum_values(A) accumulate(all(A))


const int INF=INT32_MAX/2;
const int MOD=1e9+7;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}


const int MAX = 1000;

void rec(const vector<vector<long long>> &dp, const vector<int> &a, int i, int j, deque<int> &keiro, vector<deque<int>> &ans) {
    if (i == 0) {
        if (j == 0) {
            ans.push_back(keiro);
        }
        return;
    }

    // 上へ遡る (dp[i-1][j] == 0) だったら無視)
    if (dp[i-1][j]) {
        rec(dp, a, i-1, j, keiro, ans);
    }
    // 左上へ遡る (dp[i-1][j-a[i-1]] == 0 だったら無視)
    if (j-a[i-1] >= 0 && dp[i-1][j-a[i-1]]) {
        keiro.push_front(a[i-1]);
        rec(dp, a, i-1, j-a[i-1], keiro, ans);
        keiro.pop_front();
    }
}


int main() {
    int N, X;
    cin >> N >> X;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // DP
    vector<vector<long long>> dp(N+1, vector<long long>(MAX, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < MAX; ++j) {
            dp[i+1][j] += dp[i][j];
            if (j + a[i] < MAX) dp[i+1][j+a[i]] += dp[i][j];
        }
    }

    // 復元
    deque<int> keiro;
    vector<deque<int>> ans;
    rec(dp, a, N, X, keiro, ans);

    // 出力
    cout << "the num of combinations is: " << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << i+1 << " case:";
        for (auto el : ans[i]) cout << " " << el;
        cout << endl;
    }
}
