#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, H;
    cin >> N >> H;
    int A;
    vector<int> B(N);
    int Amax = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> A >> B[i];
        Amax = max(Amax, A);
    }
    sort(B.begin(), B.end(), greater<int>());
    int b = 0;
    int ans = 0;
    while (H > 0 && b < N)
    {
        if (B[b] >= Amax)
        {
            H -= B[b];
            b++;
            ans++;
        }
        else
            break;
    }
    if (H > 0)
        ans += (H + Amax - 1) / Amax;
    cout << ans << endl;
    return 0;
}