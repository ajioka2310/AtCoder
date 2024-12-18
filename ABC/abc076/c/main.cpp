#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/




string SS, T;
//---------------------------------------------------------------------------------------------------
string solve() {
    int N = SS.length();
    int M = T.length();

    set<string> ans;
    rrep(R, N, M) {
        int L = R - M;

        int ok = 1;
        rep(i, 0, M) if (SS[L + i] != '?' and SS[L + i] != T[i]) ok = 0;
        if (ok) {
            string S;
            rep(i, 0, N) S += SS[i];
            rep(i, 0, M) S[L + i] = T[i];
            rep(i, 0, N) if (S[i] == '?') S[i] = 'a';
            ans.insert(S);
        }
    }

    if(ans.size() == 0) return "UNRESTORABLE";
    return *(ans.begin());
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> SS >> T;
    cout << solve() << endl;
}