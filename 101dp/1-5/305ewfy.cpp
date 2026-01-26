#include <iostream>
#include <algorithm>


using namespace std;

const int N = 110;

int n, v, m; // 物品个数  背包容积  背包重量

int f[N][N];

int main() {
    cin >> n >> v >> m;
    for (int i = 1; i <= n; i ++) {
        int vi, mi, wi;
        cin >> vi >> mi >> wi;
        for (int j = v; j >= vi; j --) 
            for (int k = m; k >= mi; k --)
                f[j][k] = max(f[j][k], f[j - vi][k - mi] + wi);
    }
    printf("%d", f[v][m]);
    return 0;
}










