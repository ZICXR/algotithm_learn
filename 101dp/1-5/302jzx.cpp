#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20010;

int f[N], v, n;

int main() {
    cin >> v;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int w;
        cin >> w;
        for (int j = v; j >= w; j --) f[j] = max(f[j], f[j - w] + w);
    }
    cout << v - f[v] << endl;
    return 0;
}



