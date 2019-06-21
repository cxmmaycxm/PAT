#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int num);

int main(){
    int num,preNum,currentNum,primeNum;//   ���������ǰһ����������ǰ��������������
    primeNum = 0;
    preNum = currentNum = 3;
    cin >> num;
    //  �Դ���4������������
    if(num > 4){
        for( int i=5; i<=num; i++){
            if( true == isPrime(i)){
                currentNum = i;
                if( 2 == currentNum - preNum){
                    primeNum ++;
                }
                preNum = currentNum;
            }
        }
    }
    cout << primeNum;
	return 0;
}

//  �ж��Ƿ�������
bool isPrime(int num){
    if( num <= 3){
        return num > 1;
    }
    int sqrtNum = (int) sqrt( (double)num );
    for(int i=2; i<=sqrtNum; i++){
        if( 0 == num%i ){
            return false;
        }
    }
    return true;
}
