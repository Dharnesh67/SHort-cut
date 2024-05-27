#include <bits/stdc++.h>
using namespace std;
void f(vector<vector<char>> &grid, int i, int j)
{
  if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] != '1')
    return;
  grid[i][j] = '0';
  f(grid, i + 1, j);
  f(grid, i, j + 1);
  f(grid, i - 1, j);
  f(grid, i, j - 1);
}

int main()
{
  
}