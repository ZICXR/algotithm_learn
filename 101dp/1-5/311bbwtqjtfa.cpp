#include <iostream>

using namespace std;

const int N = 1010;

int n, m, v[N], w[N], f[N][N];

int main() {
    cin >> n >> m;
    // 先背包 这里背包 物品从后往前推 所以要先把数据读进来 再反着做
    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];
    for (int i = n; i >= 1; i --) {
        for (int j = 0; j <= m; j ++) {
            f[i][j] = f[i+1][j];  // 从后向前推
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    }
    // 价值最大表示 f[1][m]
    // 找方案数 贪心
    int j = m; // 总体积   根据这个体积 逐个向后推 判断物品是否加入
    for (int i = 1; i <= n; i ++) {
        // 如果 f[i][j] == f[i + 1][j - v[i]] + w[i]  可以加入
        // 必选 注意 这里也包含了可选可不选的情况 f[i + 1][j - v[i]] + w[i] == f[i][j] = f[i+1][j]时
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i]) {
            cout << i << ' ';
            j -= v[i];  // 
        }
    }
    return 0;
}





