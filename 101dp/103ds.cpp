#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int f[N], g[N];
int w[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        scanf("%d", &w[i]);
    
    for (int i = 1; i <= n; i ++) {
        f[i] = 1;
        for (int j = 1; j < i; j ++)
            if (w[j] < w[i]) f[i] = max(f[i], f[j] + 1);
    }
    for (int i = n; i >= 1; i --) {
        g[i] = 1;
        for (int j = n; j > i; j --) 
            if (w[j] < w[i]) g[i] = max(g[i], g[j] + 1);
     }
    int res = 0;
    for (int i = 1; i <= n; i ++) res = max(res, f[i] + g[i] - 1);
    cout << res << endl;
    return 0;
}




