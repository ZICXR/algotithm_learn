#include <iostream>
#include <cstring>

using namespace std;

const int N = 220;

int n, f[N][N], w[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int a;
        cin >> a;
        w[i] = a;
        w[i + n] = a;
    }
    for (int len = 3; len <= n + 1; len ++)  // 这里要加上最后的一个尾巴
        for (int l = 0; l + len - 1 < n * 2; l ++) {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k ++)
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]);
        }
    int maxv = 0;
    for (int i = 0; i < n; i ++) maxv = max(maxv, f[i][i + n]); // f[i][i + n] 不减一是因为要考虑到首尾相连
    cout << maxv << endl;
    return 0;
}




