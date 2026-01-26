#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int f[N], n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int v, w, s;
        cin >> v >> w >> s;
        if (!s) { // 完全背包
            for (int j = v; j <= m; j ++)
                f[j] = max(f[j], f[j - v] + w);
        } else {
            if (s == -1) s = 1; //  01背包
            for (int k = 1; k <= s; k *= 2) {
                for (int j = m; j >= k * v; j --)
                    f[j] = max(f[j], f[j - k * v] + k * w);
                s -= k;  // 减去选完的
            }

            if (s) { // s 还有剩余的
                for (int j = m; j >= s * v; j --)
                    f[j] = max(f[j], f[j - s * v] + s * w);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}








