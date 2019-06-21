/*#include <iostream>
#include <string>
#define MAX 80

using namespace std;

int main(){
    string input[MAX];
    int i=0;
    while ( cin >> input[i++] ){
        if('\n' == cin.get()){
            break;
        }
    }
    while ( --i > 0){
        cout << input[i] << " ";
    }
    cout << input[i];
    return 0;
}*/

#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<string> v;
    string s;
    while(cin >> s) {
        v.push(s);
    }
    cout << v.top();
    v.pop();
    while(!v.empty()) {
        cout << " " << v.top();
        v.pop();
    }
    return 0;
}
