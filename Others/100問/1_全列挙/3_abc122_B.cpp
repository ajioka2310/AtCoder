#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)



bool contain_check(string s){
    int N = s.size();
    bool check = true;
    rep(i,N){
        char _s = s[i];
        if (_s=='A' || _s=='C'|| _s=='G' || _s=='T'){
        }
        else{
            check = false;
        }
    }
    return check;
}


int main(){
    string s;
    cin >> s;
    int maxrange = 0;
    int N = s.length();
    // 左からi個消して、左からj個とる。
    rep(i,N){
        rep(j,N-i+1){
            string tmp_s = s.substr(i,j);
            int tmp_s_length = tmp_s.length();
            // 含まれる文字がACGTのみか判定する
            bool check = contain_check(tmp_s);
            if (check){
                maxrange = max(maxrange, tmp_s_length);
            }
        }
    }
    cout << maxrange << endl;
}