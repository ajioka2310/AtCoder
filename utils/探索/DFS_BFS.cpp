void dfs(const Graph &G, int v, int& ptr) {
    // 行きがけ順をインクリメントしながらメモ
    first_order[v] = ptr++;

    seen[v] = true; 
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v, ptr);
    }

    // 帰りがけ順をインクリメントしながらメモ
    last_order[v] = ptr++;
}

void bfs(){
    //Queueを生成
    queue<P> que;
    //最初の要素をキューに追加
    que.push(P(sy, sx));

    //キューの要素がなくまるまで処理を行う
    while(que.size()){
        //最初の要素を取り出す
        P p = que.front();
        que.pop();
        //処理に適した繰り返し処理
        for(int i=0; i<4; i++){
            //何かしらの処理
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            //キューに追加する条件
            if(....){
                //何かしらの処理

                //キューに追加
                que.push(P(ny, nx));
            }
        }
    }
}