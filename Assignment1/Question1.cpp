#include<cstdio>
#include<iostream>
using namespace std;

int Solution1(int n, int m) {
	if (n < 0 || m < 0) return 0;//��n����mС��0ʱ˵�������ڸ÷���
	if (m == 0) return 1;//��n>=0��m==0ʱ˵������һ�����еķ���
	return Solution1(n - 1, m - 1) + Solution1(n - 3, m - 2);//�ݹ�Ѱ�ҵ�m-1���͵�m-2��̨�׷���
}
int main() {
	//������Ҫ������m��̨��ʱ�ķ���ֻ�����֣���һ���Ǵ�m-1��̨��������m�����ڶ����Ǵ�m-2��̨������m�����ɴ˿����뵽�Եݹ�ķ�ʽ���������
	//���һ�������������n��·�ﵽ���m��̨�׵��ܷ�����
	int n, m;
	cin >> m >> n;
	cout << Solution1(n, m) << endl;

	return 0;
}