#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n = matrix.size();
	int m = matrix[0].size();
	int col = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				if (j == 0) {
					col = 0;
				}
				else {
					matrix[0][j] = 0;
				}
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < m; i++) {
		if (matrix[0][0] == 0) {
			matrix[0][i] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (col == 0) {
			matrix[i][0] = 0;
		}
	}
}
