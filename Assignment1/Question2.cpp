#include<cstdio>
#include<iostream>
using namespace std;
int GetMinLeft(int n, int m) {
	if (n < 0 || m < 0) return INT_MAX;//不成立的方案则返回一个很大的数
	if (m == 0) return n;//方案成立则返回该剩余量n
	return min(GetMinLeft(n - 1, m - 1), GetMinLeft(n - 3, m - 2));//返回使得n最小（即消耗的n最大）的方案
}

int Solution2(int n, int m) {//此时的n表示必须消耗的卡路里数
	if (n < 0 || m < 0) return 0;//当n或者m小于0时说明不存在该方法
	if (m == 0 && n == 0) return 1;//当n==0且m==0时说明这是一条符合要求的可行的方案
	return Solution2(n - 1, m - 1) + Solution2(n - 3, m - 2);//递归寻找第m-1级和第m-2级台阶方案
}
int main() {
	//考虑到需要消耗最多卡路里，则可以先用递归算法求出所用方案剩余的卡路里最少的量n_MinLeft，再用一次递归算法求出符合该剩余量的所有方案数
	int n, m;
	cin >> m >> n;
	int n_MinLeft=GetMinLeft(n, m);
	cout << Solution2(n - n_MinLeft, m) << endl;

	return 0;
}