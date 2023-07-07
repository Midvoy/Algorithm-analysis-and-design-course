#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findGold(vector<vector<int> >& grid, int x, int y) {
	int sum = 0;
	int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
	int temp = grid[x][y];
	grid[x][y] = 0;
	for (int i = 0; i < 4; ++i) {
		int u = x + dir[i][0], v = y + dir[i][1];
		if (u >= 0 && u < grid.size() && v>=0 && v < grid[x].size()) {
			if (grid[u][v] != 0) {
				sum = max(sum, findGold(grid, u, v));
			}
		}
	}
	grid[x][y] = temp;
	return sum + grid[x][y];
}

int getMaximumGold(vector<vector<int> >& grid) {
	int ans = 0;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[i].size(); ++j) {
			if (grid[i][j] != 0) {
				ans=max(ans,findGold(grid, i, j));
			}
		}
	}
	return ans;
}


int main() {

	string lineStr;
	getline(cin,lineStr);
	vector<vector<int>> grid;

	string number;
	bool num_end = false;
	bool line_end = false;
	int target = -1;
	bool result;
	vector<int> line;
	for (int i = 0; i < lineStr.size(); i++) {
		if (!num_end) {
			if (lineStr[i] == '[') {
				line_end = false;
				line.clear();
			}
			else if (lineStr[i] == ']' && line_end) {
				number = "";
				num_end = true;
			}
			else if (lineStr[i] == ']' && !num_end) {
				line.push_back(atoi(number.c_str()));
				grid.push_back(line);
				line_end = true;
				number = "";
			}

			else if (lineStr[i] >= '0' && lineStr[i] <= '9')number += lineStr[i];
			else if (lineStr[i] == ',' && !line_end) {
				line.push_back(atoi(number.c_str()));
				number = "";
			}
		}
	}

	cout << getMaximumGold(grid) << endl;

	system("pause");

	return 0;
}
//grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
