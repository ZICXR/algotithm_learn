// 1 质数在大于1的整数中，如果只包含1和本身这两个约数，就被称为质数或素数。
// （1）质数的判定--试除法 O(n)
//  优化 试除法 O(√n)  若n / d = b ,则n / b = d, 所以只枚举灭蚁队中较小的
//       即只判定 d <= n / d => d * d <= n => d <= √n 的数即可 
// 
// (2) 分解质因数 -- 试除法
#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / i; i ++) 
        if (n % i == 0)
        return false;
    return true;
}


int main() {
    
}


