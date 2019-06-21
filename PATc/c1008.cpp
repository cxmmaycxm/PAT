#include <iostream>
#include <algorithm>

using namespace std;

/**
*   问题：数组循环右移问题
*   原先解决思路：按规则存入数组再输出
*   参考正确思路：进行三次反转
*   进行过程中遇到的问题：
*       1.移动位数大于数组位数的情况没进行处理，应m%=n；
*       2.reverse()函数第二个参数是移动最后一位的下一位；
*       3.除最后一位，其他都输出“ ”的操作可以如29-32行所示
*/

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    m %= n;
    if( 0 != m) {
        reverse(a, a+n-m);
        reverse(a+n-m, a+n);
        reverse(a, a+n);
    }
    for(int i=0; i<n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1];
    return 0;
}
