#include<bits/stdc++.h>

using namespace std;

// 二分探索でx以上の最小のインデックスを返す関数
int lb(int x,vector<int> &a){
  int l=0,r=((int)a.size())-1;
  while(l<=r){
    int te=(l+r)/2;
    if(a[te]<x){l=te+1;}
    else{r=te-1;}
  }
  return l;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;
  cin >> n >> q; // n: 文字列の長さ, q: クエリの数
  string s;
  cin >> s; // 文字列の入力
  vector<int> c1(n+1,0); // '1'の累積和
  vector<int> c2(n+1,0); // '2'の累積和
  vector<int> sl; // '3'の位置を保存するベクトル
  for(int i=0;i<n;i++){
    c1[i+1]=c1[i];
    c2[i+1]=c2[i];
    if(s[i]=='1'){
      c1[i+1]++;
    }
    else if(s[i]=='2'){
      c2[i+1]++;
    }
    else{
      sl.push_back(i+1); // '3'の位置を保存
    }
  }

  while(q>0){
    q--;
    int l,r;
    cin >> l >> r; // クエリの範囲を入力
    int lef=lb(l,sl); // l以上の最小の'3'の位置
    int rig=lb(r+1,sl); // r以下の最大の'3'の位置
    if(lef==rig){
      cout << "0\n"; // '3'が範囲内に存在しない場合
      continue;
    }
    rig--;

    int res=0;
    while(lef<=rig){
      int te=(lef+rig)/2;
      int pt=sl[te];

      int l1=(c1[pt]-c1[l-1]); // lからptまでの'1'の数
      int r2=(c2[r]-c2[pt]); // ptからrまでの'2'の数

      res=max(res,2*min(l1,r2)+1); // 最大の部分文字列の長さを更新

      if(l1>r2){rig=te-1;} // '1'の数が多い場合
      else{lef=te+1;} // '2'の数が多い場合
    }
    cout << res << "\n"; // 結果を出力
  }
  return 0;
}
