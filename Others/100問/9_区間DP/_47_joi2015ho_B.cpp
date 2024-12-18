#include<bits//stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
#define rep(i,n) for(int i = 0;i<n;i++)
int main() {
    int n; cin >> n; vector<int> t(n); 
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) cin >> t[i];
    rep(i, n) rep(j, n) cin >> a[i][j];
    vector<int> dp(1 << n, 1e9); dp[0] = 0;
    rep(bit, 1 << n) {
        rep(j, n) {
            if (!(bit >> j & 1)) {
                int sum = 0;
                rep(k, n) {
                    if (bit >> k & 1)sum += a[k][j];
                }chmin(dp[bit | (1 << j)], dp[bit] + t[j] - sum);
            }
        }
    }cout << dp[(1 << n)-1] << endl;
}  
