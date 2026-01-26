#include <cstring>
#include <iostream>


using namespace std;


const int N = 100010, K = 110;

int n, k, f[N][K][2]; // 前 i 天 当前是第 j 次交易时，状态是 0或1 时的最大值  0 表示未持有股票  1 表示不持有股票

int main() {
    cin >> n >> k;
    memset(f, -0x3f, sizeof f);
    f[0][0][0] = 0;
    for (int i = 0; i <= n; i ++) f[i][0][0] = 0; // 合法 ******
    for (int i = 1; i <= n; i ++) {
        int w;
        cin >> w;
        for (int j = 1; j <= k; j ++) {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w);
            f[i][j][1] = max(f[i - 1][j - 1][0] - w, f[i - 1][j][1]);
        }
    }
    int res = 0;
    for (int i = 1; i <= k; i ++) res = max(res, f[n][i][0]); // 最后不持有股票一定最好
    cout << res << endl;
    return 0;
}





