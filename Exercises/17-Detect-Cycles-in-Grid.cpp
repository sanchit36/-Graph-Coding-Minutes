#include <bits/stdc++.h>
using namespace std;

static int D_FOUR[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool dfs(vector<vector<char>> &matrix,
         vector<vector<int>> &visited,
         int i_curr, int j_curr,
         int i_prev, int j_prev)
{

  if (visited[i_curr][j_curr] == 1)
    return true;

  visited[i_curr][j_curr] = 1;

  for (int k = 0; k < 4; k++)
  {
    int i_next = i_curr + D_FOUR[k][0];
    int j_next = j_curr + D_FOUR[k][1];
    if (i_next < 0 || j_next < 0 || i_next >= matrix.size() || j_next >= matrix[0].size())
      continue;

    if (matrix[i_next][j_next] != matrix[i_curr][j_curr])
      continue;

    if (i_next == i_prev && j_next == j_prev)
      continue;
    if (dfs(matrix, visited, i_next, j_next, i_curr, j_curr))
      return true;
  }

  return false;
}

bool containsCycle(vector<vector<char>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> visited(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      if (visited[i][j] == 1)
        continue;
      if (dfs(grid, visited, i, j, i, j))
        return true;
    }
  }
  // We checked each cell and couldn't find a cycle of 4 or more so return false
  return false;
}

int main()
{
  vector<vector<char>> grid = {
      {'a', 'a', 'a', 'a'},
      {'a', 'b', 'b', 'a'},
      {'a', 'b', 'b', 'a'},
      {'a', 'a', 'a', 'a'},

  };

  cout << containsCycle(grid) << endl;

  return 0;
}