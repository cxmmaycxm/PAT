#include <iostream>
#include <string>
#include <sstream>
#define A 'A'
#define G 'G'
#define N 'N'
#define Z 'Z'
#define MAX 60

using namespace std;

/**
*   û��AC
*/

int main() {
    string day[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    string dayStr, hhStr, mmStr;
    char first[MAX], second;
    bool daySucceed, hhSucceed, mmSucceed ;
    daySucceed = hhSucceed = mmSucceed = false;
    int i=0;
    dayStr = hhStr = mmStr = "";
    cin >> first;
    cin.get();
    while( '\n' != (second = cin.get())) {
        //  �Ƚϵ�һ����ͬ
        if( false == daySucceed && second == first[i++] && second >= A && second <= G ) {
            dayStr = day[second-A] ;
            daySucceed = true;
            continue;
        }
        //  �Ƚϵڶ�����ͬ
        if( true == daySucceed) {
            if( second == first[i++] ) {
                if( second >= '0' && second <= '9' ) {
                    stringstream ss;
                    ss << ( second - '0' ) ;
                    ss >> hhStr ;
                    hhStr = "0" + hhStr;
                    hhSucceed = true;
                    break;
                } else if ( second >= A && second <= N ) {
                    stringstream ss;
                    ss << ( second - A + 10 );
                    ss >> hhStr ;
                    hhSucceed = true;
                    break;
                }
            }
        }
    }
    //  ���ڶ��������ַ���ȫ��ȡ
    if( hhSucceed && daySucceed ) {
        while ( '\n' != (second = cin.get()) ) {}
    }
    //  �Ƚϵ�������ͬ
    if( daySucceed && hhSucceed ) {
        cin >> first;
        cin.get();
        i = 0;
        while( '\n' != (second = cin.get())) {
            if( second == first[i++] &&
                    (( second >= 'a' && second <= 'z' ) || ( second >= A && second <= Z )) ) {
                stringstream ss;
                ss << ( i - 1 );
                ss >> mmStr;
                if ( 0 < i && 10 > i ) {
                    mmStr = "0" + mmStr;
                }
                mmSucceed = true;
                break;
            }
        }
    }

    //  ���
    if( daySucceed && hhSucceed && mmSucceed ) {
        cout << dayStr << " " << hhStr << ":" << mmStr;
    }
    return 0;
}
