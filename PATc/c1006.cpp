#include <iostream>

using namespace std;

int main(){
	int num;
	cin >> num;
	//	输出百位数
	for( int i = num/100; i > 0; i--){
		cout << "B";
	}
	num %= 100;
	//	输出十位数
	for( int i = num/10; i > 0; i--){
		cout << "S";
	}
	num %= 10;
	//	输出个位数
	for( int i=1; i < num+1; i++){
		cout << i;
	}
	return 0;
}