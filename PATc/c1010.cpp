#include <iostream>

using namespace std;

/**
*   ��Ŀ����������⣺
*   1.�����������һ����ϵ����һ����ָ�������Ұ�ϵ���������ݣ�����һֱ������������
*   2.����Ϊ�����ʽ����������Ϊ��0 0������һֱ�޷������Ŀ�������ʽ�����һ�仰����ΪΪ0 0ʱ�����������
**/
int main() {
    int m,n;
    bool first = true;
    while(cin >> m >> n) {
        //  ϵ����ָ��Ϊ0,�޵���
        if( 0 == m || 0 == n ) {
            continue;
        } else {
            if(true == first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << m*n << " " << n-1;
        }
    }
    //  ����������ʽ���������0 0��
    if( true == first){
        cout << "0 0";
    }
    return 0;
}
