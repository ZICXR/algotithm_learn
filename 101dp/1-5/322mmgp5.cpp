#include <cstring>
#include <iostream>


using namespace std;

const int N = 100010;

int n, f[N][3]; // 前i天 时 状态是 1 表示不持有股票第一天  2 表示 不持有股票第>=2天  0 表示持有股票

int main() {
    cin >> n;
    memset(f, -0x3f, sizeof f);
    f[0][2] = 0;
    for (int i = 1; i <= n; i ++) {
        int w;
        cin >> w;
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - w);
        f[i][1] = f[i - 1][0] + w;
        f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }

    int res = 0;
    res = max(f[n][1], f[n][2]); // 最优答案一定是 不持有股票时
    cout << res << endl;
    return 0;
}






