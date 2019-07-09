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
*   �ò�����AC�ˣ���Ŀ���ѣ�Сϸ���ر��
*   ϸ�ڣ�
*   1.�ڶ������ڵ�һ���ҵ�����������µģ�����Ҫ���������֮��Ĺ�ϵ����ϵ
*   2.����Ҫ�� xx:xx ����ʽ���ڣ����Ե������ֵ�Ҫע��Ӹ�'0'
*/

int main() {
    string day[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    string dayStr, hhStr, mmStr;
    char first[MAX], second[MAX], third[MAX], forth[MAX];
    bool daySucceed, hhSucceed, mmSucceed ;
    daySucceed = hhSucceed = mmSucceed = false;
    dayStr = hhStr = mmStr = "";
    cin >> first >> second >> third >> forth ;
    for( int i=0; ('\0' !=  first[i]) && ('\0' != second[i]); i++ ) {
        //  �Ƚϵ�һ����ͬ����һ����ͬ�Ĵ�д��ĸ��
        if( false == daySucceed && second[i] == first[i] && second[i] >= A && second[i] <= G ) {
            dayStr = day[second[i]-A] ;
            daySucceed = true;
            continue;
        }
        //  �Ƚϵڶ�����ͬ���ڶ�����ͬ���ַ���0-9��A-N��
        if( true == daySucceed && second[i] == first[i] ) {
            if( second[i] >= '0' && second[i] <= '9' ) {
                stringstream ss;
                ss << ( second[i] - '0' ) ;
                ss >> hhStr ;
                hhStr = "0" + hhStr;
                hhSucceed = true;
                break;
            } else if ( second[i] >= A && second[i] <= N ) {
                stringstream ss;
                ss << ( second[i] - A + 10 );
                ss >> hhStr ;
                hhSucceed = true;
                break;
            }
        }
    }
    //  �Ƚϵ�������ͬ���ڶ����ַ�����һ����ͬ��Ӣ����ĸ���±꣩
    if( daySucceed && hhSucceed ) {
        for( int i = 0; ('\0' != third[i]) && ('\0' != forth[i]); i++ ) {
            if( forth[i] == third[i] &&
                    (( forth[i] >= 'a' && forth[i] <= 'z' ) || ( forth[i] >= A && forth[i] <= Z )) ) {
                stringstream ss;
                ss << i;
                ss >> mmStr;
                if ( 0 <= i && 9 >= i ) {
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
