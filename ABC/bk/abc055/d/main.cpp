#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S, tmp, res = "-1";
    cin >> N >> S;

    auto flip = [&](char c) -> char { return (c == 'S' ? 'W' : 'S'); };
    auto check = [&](char front, char back) -> string {
        string res = string(N, '.');
        res[0] = front, res.back() = back;
        for (int i = 0; i < N; i++) {
            char c;
            if (res[i] == 'S') {
                if (S[i] == 'o') c = res[(i+N-1)%N];
                else c = flip(res[(i+N-1)%N]);
            } else {
                if (S[i] == 'o') c = flip(res[(i+N-1)%N]);
                else c = res[(i+N-1)%N];
            }

            // 整合性 check
            if (res[(i+1)%N] == '.') res[(i+1)%N] = c;
            else if (c != res[(i+1)%N]) return "-1";
        }
        return res;
    };

    if ((tmp = check('S', 'S')) != "-1") res = tmp;
    if ((tmp = check('S', 'W')) != "-1") res = tmp;
    if ((tmp = check('W', 'S')) != "-1") res = tmp;
    if ((tmp = check('W', 'W')) != "-1") res = tmp;
    cout << res << endl;
}