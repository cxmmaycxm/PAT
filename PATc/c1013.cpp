#include <iostream>
#include <math.h>

using namespace std;

/**
*   �������⣺
*   1.����������ǰ����
*   2.˼·���������ؼ��ڵ㴦û���պã�������ơ� ���͡�\n���ı���c֮ǰ�Ϳ��Ƶ�ǰ�����±��i���;
*   3.��ľ�������cout������,cout����Ҫ����Ķ���Ӧ�����������Ű�Χ������
**/

bool isPrime(int num);

int main(){
    int  m, n, num, i, c;
    i = c = 0;  //  ��ǰ�����±꣬�������
    num = 2;//  ��ǰ��
    cin >> m >> n;
    while(true){
        //  ����Χʱ��Ĵ���
        if( i>n){
            break;
        } else {
            //  ���������
            if( true == isPrime(num)){
                i++;
                //  �ڷ�Χ�ڵ����
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

//  �ж��Ƿ�������
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
