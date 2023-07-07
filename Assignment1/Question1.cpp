#include<cstdio>
#include<iostream>
using namespace std;

int Solution1(int n, int m) {
	if (n < 0 || m < 0) return 0;//当n或者m小于0时说明不存在该方法
	if (m == 0) return 1;//当n>=0且m==0时说明这是一条可行的方案
	return Solution1(n - 1, m - 1) + Solution1(n - 3, m - 2);//递归寻找第m-1级和第m-2级台阶方案
}
int main() {
	//考虑需要爬到第m级台阶时的方法只有两种，第一种是从m-1级台阶爬到第m级，第二种是从m-2级台阶爬到m级，由此可以想到以递归的方式解决该问题
	//设计一个函数解决可用n卡路里到达第m级台阶的总方法数
	int n, m;
	cin >> m >> n;
	cout << Solution1(n, m) << endl;

	return 0;
}