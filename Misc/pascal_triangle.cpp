#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 1024
#define MAX_M 1024

using namespace std;
void buildPascalTriangle(int n, int m) {

	vector<vector<int> >  bMat(MAX_N, vector<int>(MAX_M));

	int i = 0, j = 0;

	for (i = 0; i <= n; ++i)
		bMat[i][0] = 1;
	for (j = 0; j <= m; j++)
		bMat[j][j] = 1;


	for (i = 1; i <= n; i++) {
		for (j = 1; j < i; j++) {
			bMat[i][j] = bMat[i - 1][j] + bMat[i - 1][j - 1];
		}
	}

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			cout << bMat[i][j] << "\t";
		}
		cout << "\n";
	}


}


int main() {

	int n, m;
	cin >> n >> m;

	buildPascalTriangle(n, m);

	return 0;

}