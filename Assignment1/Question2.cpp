#include<cstdio>
#include<iostream>
using namespace std;
int GetMinLeft(int n, int m) {
	if (n < 0 || m < 0) return INT_MAX;//�������ķ����򷵻�һ���ܴ����
	if (m == 0) return n;//���������򷵻ظ�ʣ����n
	return min(GetMinLeft(n - 1, m - 1), GetMinLeft(n - 3, m - 2));//����ʹ��n��С�������ĵ�n��󣩵ķ���
}

int Solution2(int n, int m) {//��ʱ��n��ʾ�������ĵĿ�·����
	if (n < 0 || m < 0) return 0;//��n����mС��0ʱ˵�������ڸ÷���
	if (m == 0 && n == 0) return 1;//��n==0��m==0ʱ˵������һ������Ҫ��Ŀ��еķ���
	return Solution2(n - 1, m - 1) + Solution2(n - 3, m - 2);//�ݹ�Ѱ�ҵ�m-1���͵�m-2��̨�׷���
}
int main() {
	//���ǵ���Ҫ������࿨·���������õݹ��㷨������÷���ʣ��Ŀ�·�����ٵ���n_MinLeft������һ�εݹ��㷨������ϸ�ʣ���������з�����
	int n, m;
	cin >> m >> n;
	int n_MinLeft=GetMinLeft(n, m);
	cout << Solution2(n - n_MinLeft, m) << endl;

	return 0;
}