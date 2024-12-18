#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
#define vec vector<int>
#define Graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main(){
    // N,M
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y ;
    ll ans = INF;
    krep(i,0,2*(max(X,Y)+1)){
        ll tmp_ans = INF;
        if (i%2==1){
        }
        else{
            tmp_ans = C*i;
            tmp_ans += A*max((X-i/2),0);
            tmp_ans += B*max((Y-i/2),0);
        }
        ans = min(ans,tmp_ans);
    }
    cout << ans;
}