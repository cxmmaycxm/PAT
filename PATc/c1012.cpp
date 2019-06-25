#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int number, temp;
    int num[5] = {0}, a[5] = {0};
    cin >> number;
    while( number-- ) {
        cin >> temp;
        //  收集信息
        switch( temp%5 ) {
        case 0:
            if( 0 == temp % 2) {
                num[0]++;
                a[0] += temp;
            }
            break;
        case 1:
            num[1] ++;
            if( 1 == num[1] % 2) {
                a[1] += temp;
            } else {
                a[1] -= temp;
            }
            break;
        case 2:
            num[2] ++;
            break;
        case 3:
            num[3] ++;
            a[3] += temp;
            break;
        case 4:
            if( a[4] < temp ) {
                num[4] ++;
                a[4] = temp;
            }
            break;
        default:
            break;
        }
    }
    //  整理输出信息
    a[2] = num[2];
    for(int i=0; i<5; i++) {
        if( 0 == num[i]) {
            cout << "N" ;
        } else if( 3 == i ) {
            printf("%.1f", ((float)a[3])/num[3] );
        } else {
            cout << a[i];
        }
        if( 4 == i) {
            break;
        }
        cout <<" ";
    }
    return 0;
}
