#include <iostream>

using namespace std;

/**
*   注意越界问题
**/

int main() {
    int num, count;
    long long a, b, c;
    cin >> num;
    count = num;
    while( count-- ) {
        cin >> a >> b >> c ;
        cout << "Case #" << num-count << ": " << ((a+b>c) ? "true" : "false" ) <<endl;
    }
    return 0;
}
