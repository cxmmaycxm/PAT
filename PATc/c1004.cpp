#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string stu[2][2], tempName, tempSno;
    int maxScore, minScore, score;
    maxScore = -1;
    minScore = 101;
    cin >> n;
    while (0 < n--){
        cin >> tempName >> tempSno >> score ;
        if(score < 0 || score > 100 ){
            cout << "成绩输入有误，将强制停止程序" << endl;
            return 0;
        }
        if ( score > maxScore ){
            stu[0][0] = tempName;
            stu[0][1] = tempSno;
            maxScore = score;
        }
        if ( score < minScore ){
            stu[1][0] = tempName;
            stu[1][1] = tempSno;
            minScore = score;
        }
    }
    cout << stu[0][0] << " " << stu[0][1] << endl <<  stu[1][0] << " " << stu[1][1];
    return 0;
}
