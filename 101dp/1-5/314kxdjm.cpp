#include <iostream>
#include <algorithm>

using namespace std;

const int N = 30010;
int n, m, f[N];


int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int v, p;
        cin >> v >> p;
        for (int j = n; j >= v; j --) 
            f[j] = max(f[j], f[j - v] + v * p);
    }
    cout << f[n] << endl;
    return 0;
}










