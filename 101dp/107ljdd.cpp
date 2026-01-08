#include <iostream>
#include <algorithm>

using namespace std;

const int N= 1010;

int f[N], g[N], w[N];

int main() {
    int n = 1;
    while (cin >> w[n]) n ++;

    int res = 0;
    for (int i = 1; i < n; i ++) {
        f[i] = 1;
        for (int j = 1; j < i; j ++) 
            if (w[j] >= w[i]) f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    cout << res <<endl;
    int cnt = 0;
    for (int i = 1; i < n; i ++) {
        int k = 1;
        while (k < cnt + 1 && g[k] < w[i]) k ++;
        g[k] = w[i];
        if (k >= cnt + 1) cnt ++;
    }
    cout << cnt << endl;
    return 0;
}


