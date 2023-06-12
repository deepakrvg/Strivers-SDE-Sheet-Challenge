#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> mat(n, vector<int>(m, -1));
	
	unordered_map<int, int> rows;
	unordered_map<int, int> cols;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) mat[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				rows[i]++;
				cols[j]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (rows[i] || cols[j]) {
				matrix[i][j] = 0;
			}
		}
	}
}
