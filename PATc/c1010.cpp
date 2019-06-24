#include <iostream>

using namespace std;

/**
*   题目审题存在问题：
*   1.输入的两个数一个是系数，一个是指数。（我把系数当成了幂，所以一直不能理解输出）
*   2.输入为零多项式的情况，输出为“0 0”。（一直无法理解题目中输出格式的最后一句话，以为为0 0时不输出东西）
**/
int main() {
    int m,n;
    bool first = true;
    while(cin >> m >> n) {
        //  系数或指数为0,无导数
        if( 0 == m || 0 == n ) {
            continue;
        } else {
            if(true == first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << m*n << " " << n-1;
        }
    }
    //  如果是零多项式，则输出“0 0”
    if( true == first){
        cout << "0 0";
    }
    return 0;
}
