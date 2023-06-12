#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> mat(n, vector<int>(m, -1));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) mat[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				for (int k = 0; k < m; k++) {
					if (mat[i][k] != 0) {
						mat[i][k] = 1;
					}
				}
				for (int k = 0; k < n; k++) {
					if (mat[k][j] != 0) {
						mat[k][j] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != -1) {
				matrix[i][j] = 0;
			}
		}
	}
}
