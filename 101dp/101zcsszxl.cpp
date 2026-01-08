#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int w[N];
int f[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i ++) {
        f[i] = 1;  // 空集
        for (int j = 1; j < i; j ++) {
            if (w[j] < w[i]) f[i] = max(f[i], f[j] + 1);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i ++) res = max(res, f[i]);
    cout << res << endl;
    return 0;
}


