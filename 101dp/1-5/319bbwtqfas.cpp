#include <cstring>
#include <iostream>


using namespace std;

const int N = 1010, mod = 1e9 + 7;
int n, m;
int f[N], g[N];
// 这里定义 f[N] 是体积恰好等于 j  恰好 这里又是求最大 所以全置为-INF



int main() {
    cin >> n >> m;
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;
    for (int i = 1; i <= n; i ++) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j --) {
           //  if (f[j] > f[j - v] + w)  这种情况 f[j] = f[j] g[j] = g[j]
           if (f[j] < f[j - v] + w) f[j] = f[j - v] + w, g[j] = g[j - v] % mod;
           else if (f[j] == f[j - v] + w) g[j] = (g[j - v] + g[j]) % mod;
        }
    }
    // 确定最大值 
    int res = 0;
    for (int i = 0; i <= m; i ++) res = max(res, f[i]);

    int cnt = 0;

    for (int i = 0; i <= m; i ++) {
        if (res == f[i]) cnt = (cnt + g[i]) % mod;
    }
    cout << cnt << endl;
    return 0;
}






