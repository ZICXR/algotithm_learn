#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 3010;

int n, m;
LL f[N];

int main() {
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i ++) {
        int w;
        cin >> w;
        for (int j = w; j <= m; j ++) f[j] += f[j - w];
                
    }
    cout << f[m] << endl;
    return 0;
}

