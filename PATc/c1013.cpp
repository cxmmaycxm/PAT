#include <iostream>
#include <math.h>

using namespace std;

/**
*   存在问题：
*   1.方法忘记提前定义
*   2.思路不清晰，关键节点处没把握好，比如控制“ ”和“\n”的变量c之前和控制当前质数下标的i搞混;
*   3.三木运算符和cout的问题,cout后面要输出的东西应该整个用括号包围起来。
**/

bool isPrime(int num);

int main(){
    int  m, n, num, i, c;
    i = c = 0;  //  当前质数下标，输出的数
    num = 2;//  当前数
    cin >> m >> n;
    while(true){
        //  超范围时候的处理
        if( i>n){
            break;
        } else {
            //  如果是质数
            if( true == isPrime(num)){
                i++;
                //  在范围内的输出
                if( i >= m && i < n ){
                    c++;
                    cout << num << ((c%10)==0 ? "\n" : " ");
                } else if ( i == n){
                    cout << num;
                }
            }
            num ++;
        }
    }
    return 0;
}

//  判断是否是质数
bool isPrime(int num){
    if( num <= 3){
        return num > 1;
    }
    int sqrtNum = (int)sqrt( (double)num );
    for( int i=2; i<=sqrtNum; i++){
        if( 0 == num % i){
            return false;
        }
    }
    return true;
}
