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
*   好不容易AC了，题目不难，小细节特别多
*   细节：
*   1.第二个是在第一个找到的情况下往下的，所以要处理好它们之间的关系和联系
*   2.日期要以 xx:xx 的形式存在，所以单个数字的要注意加个'0'
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
        //  比较第一对相同（第一对相同的大写字母）
        if( false == daySucceed && second[i] == first[i] && second[i] >= A && second[i] <= G ) {
            dayStr = day[second[i]-A] ;
            daySucceed = true;
            continue;
        }
        //  比较第二对相同（第二对相同的字符：0-9，A-N）
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
    //  比较第三对相同（第二组字符串第一对相同的英文字母的下标）
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

    //  输出
    if( daySucceed && hhSucceed && mmSucceed ) {
        cout << dayStr << " " << hhStr << ":" << mmStr;
    }
    return 0;
}
