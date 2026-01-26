#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 510;

int f[N][M], n, m, k;
// f[i][j][k] 表示 前i个精灵 球 1不超过j 体力值 2 不超过 k的 最多捕获数量
int main() {
    cin >> n >> m >> k;
    // 球 体力 精灵
    for (int i = 1; i <= k; i ++) {
        int p, q;
        // 球 体力
        cin >> p >> q;
        for (int j1 = n; j1 >= p; j1 --)
            for (int j2 = m; j2 >= q; j2 --) 
                f[j1][j2] = max(f[j1][j2], f[j1 - p][j2 - q] + 1);
    }
    cout << f[n][m-1] << ' ';  // 皮卡丘不能死
    int k = 0;
    while (k < m && f[n][k] != f[n][m-1]) k ++; // 皮卡丘不能死
    cout << m - k << endl;
    return 0;
}








