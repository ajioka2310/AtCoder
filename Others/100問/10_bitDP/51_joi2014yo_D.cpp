#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>
#define Graph vector<vector<int>>
#define pair_int pair<int,int>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()
const int INF=INT32_MAX/2;
const int MOD=10007;

// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;

int main(){
    int N; cin>>N;
    string s;cin>>s;
    vector<char> ls(s.begin(),s.end());
    map<char,int> dict{{'J',0},{'O',1},{'I',2},};
    Graph dp(N,vec(8,0));
    // cpp_dump(dict);
    // cpp_dump(dp);
    // 1日目
    int bef = dict['J'];
    int aft = dict[ls[0]];
    // cpp_dump(bef,aft,ls[0]);
    rep(i,8){
        if (i&(1<<bef)&&i&(1<<aft)) dp[0][i] = 1;
    }
    // 2日目以降
    krep(i,1,N){
        // i行の探索
        rep(j,8){
            // チェック先
            rep(k,8){
                if (j&k && j&(1<<dict[ls[i]])){
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] = dp[i][j]%MOD;
                } 
            }
        }

    }

    // cpp_dump(dp);
    int ans = 0;
    rep(i,8){
        ans += dp[N-1][i];
        ans = ans%MOD;
    }
    cout << ans << endl;
}
