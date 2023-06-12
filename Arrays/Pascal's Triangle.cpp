#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> pascal_triangle(n);
  for (int i = 0; i < n; i++) {
    pascal_triangle[i].assign(i + 1, 1);
    for (int j = 0; j < pascal_triangle[i].size(); j++) {
      if (i == 0 || j == 0) {
        continue;
      }
      if (i != j) {
        pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j];
      }
    }
  }
  return pascal_triangle;
}
