#include <iostream>
#include <algorithm>

using namespace std;

/**
*   ���⣺����ѭ����������
*   ԭ�Ƚ��˼·��������������������
*   �ο���ȷ˼·���������η�ת
*   ���й��������������⣺
*       1.�ƶ�λ����������λ�������û���д���Ӧm%=n��
*       2.reverse()�����ڶ����������ƶ����һλ����һλ��
*       3.�����һλ������������� ���Ĳ���������29-32����ʾ
*/

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    m %= n;
    if( 0 != m) {
        reverse(a, a+n-m);
        reverse(a+n-m, a+n);
        reverse(a, a+n);
    }
    for(int i=0; i<n-1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1];
    return 0;
}
