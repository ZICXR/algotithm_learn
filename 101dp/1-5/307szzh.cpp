#include <cstring>
#include <iostream>

using namespace std;

const int NN = 10010;
int N, M;
int f[NN];  

int main() {
    cin >> N >> M;
    f[0] = 1;
    for (int i = 1; i <= N; i ++) {
        int n;
        cin >> n;
        for (int j = M; j >= n; j --)
            f[j] = f[j] + f[j-n];
    }
    printf("%d", f[M]);
    return 0;
}

