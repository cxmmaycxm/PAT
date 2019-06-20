#include <iostream>
#include <algorithm>
#define MAX 200

using namespace std;

bool inValue(int temp, int value[MAX], int valueLen);

int main(){
	int value[MAX], key[MAX], n, valueLen, keyLen ,temp;
	valueLen = keyLen = 0;
	cin >> n;
	while( 0 < n-- ){
		cin >> temp;
		//	如果当前数被覆盖，则继续查看下一个数
		if( true == inValue(temp, value, valueLen) ){
			continue;
		} else {
			//	如果当前数未被覆盖，先存入关键字数组
			key[keyLen++] = temp;
			//	进行3n+1猜想操作，把得到的数都放入被覆盖数组中
			while ( 1 != temp ){
				if( 1 == temp%2 ){
					temp = temp * 3 + 1;
				}
				temp /= 2;
				if( true == inValue(temp, value, valueLen) ){
					continue;
				}
				value[valueLen++] = temp;
			}
		}
	}
	//	对关键字数组进行处理，清除非关键字（出现在value数组中的）,进行排序
	int newKey[MAX], newKeyLen;
	newKeyLen = 0;
	sort(value, value+valueLen);
	for( int i=0; i<keyLen; i++ ){
		if( false == inValue(key[i], value, valueLen) ){
			newKey[newKeyLen++] = key[i];
		}
	}
	sort(newKey,newKey+newKeyLen);
	//	输出结果
	for(int i=newKeyLen; i>0; i--){
		cout<<newKey[i-1];
		if( 0 != i-1 ){
			cout << " ";
		}
	}

	return 0;
}

//	判断是否在value数组中
bool inValue(int temp, int value[MAX], int valueLen){
	for(int i=0; i < valueLen; i++){
		if( temp == value[i] ){
			return true;
		}
	}
	return false;
}
