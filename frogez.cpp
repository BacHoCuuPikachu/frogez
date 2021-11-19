#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int maxn = 1e5 + 10;
const int mod = 123456789;
int n, k;
int a[maxn];
int b[15];
int dp[maxn]; // có dp[i] cách nhảy tới điểm thứ i

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    sort(b + 1, b + k + 1);
    dp[0] = 1; // có 1 cách nhảy tới điểm thứ 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - b[j] < 0) break;
            dp[i] = (dp[i] + dp[i - b[j]]) % mod; // có thể tới i từ i - b[j],
                                                  // với mỗi cách tới i - b[j],
                                                  // ta có thêm 1 cách tới i.
        }
    }
    cout << dp[n];
}
