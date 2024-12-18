#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

ll dp[(1 << 16)][16];
ll cnt[(1 << 16)][16];

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<pair<ll, ll>>> G(N, vector<pair<ll, ll>>(N, {INF, 0}));

    for(int i = 0; i < M; i++){
        int a, b;
        ll d, t;
        cin >> a >> b >> d >> t;
        a--; 
        b--; 
        G[a][b] = {d, t};
        G[b][a] = {d, t};
    }

    for(int i = 0; i < (1 << N); i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = INF;
            cnt[i][j] = 0;
        }
    }

    dp[0][0] = 0;
    cnt[0][0] = 1;

    for(int S = 1; S < (1 << N); S++){
        // 移動先
        for(int i = 0; i < N; i++){
            // 移動先が要素のないときは処理をしない
            if(!(S & (1 << i))) continue;
            // 移動元
            for(int j = 0; j < N; j++){
                // 移動元->移動先 + 移動コスト
                if(dp[S - (1 << i)][j] + G[j][i].first <= G[j][i].second){
                    // 移動コストの集計、移動パターン
                    if(dp[S][i] > dp[S - (1 << i)][j] + G[j][i].first){
                        dp[S][i] = dp[S - (1 << i)][j] + G[j][i].first;
                        cnt[S][i] = cnt[S - (1 << i)][j];
                    // 移動パターン　記憶済みコストの場合カウントだけ追加する
                    } else if(dp[S][i] == dp[S - (1 << i)][j] + G[j][i].first){
                        cnt[S][i] += cnt[S - (1 << i)][j];
                    }
                }
            }
        }
    }

    if(dp[(1 << N) - 1][0] != INF)
        cout << dp[(1 << N) - 1][0] << " " << cnt[(1 << N) - 1][0] << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
