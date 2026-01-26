#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, M = 25010;

int T, n, a[N], f[M];

int main() {
    cin >> T;
    while (T --) {
        cin >> n;
        for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
        sort(a, a + n);
        int m = a[n - 1]; // 要一直表示到最后一个数
        memset(f, 0, sizeof f);
        f[0] = 1;
        int res = 0;
        for (int i = 0; i < n ; i ++) {
            if (!f[a[i]]) res ++;  // 如果 ai 不能被表示
            for (int j = a[i]; j <= m; j ++)
                f[j] += f[j - a[i]];  // 这里可以理解为用小的把所有比他大的表示一遍

        }
        cout << res << endl;
            
    }
    return 0;
}












