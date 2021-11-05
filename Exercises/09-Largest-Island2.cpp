#include <bits/stdc++.h>
using namespace std;

// 4way dfs
int dfs(pair<int, int> node, vector<vector<int>> &g, vector<vector<bool>> &visited)
{
  int x = node.first, y = node.second;
  int m = g.size(), n = g[0].size();
  int ca = 1;
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  visited[x][y] = true;

  for (int k = 0; k < 4; k++)
  {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] == 1 && !visited[nx][ny])
    {
      int subarea = dfs({nx, ny}, g, visited);
      ca += subarea;
    }
  }

  return ca;
}

int maxAreaOfIsland(vector<vector<int>> grid)
{
  int m = grid.size(), n = grid[0].size(), maxArea = 0;
  // visited matrix
  vector<vector<bool>> visited(m, vector<bool>(n, false));

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!visited[i][j] && grid[i][j] == 1)
      {
        int area = dfs({i, j}, grid, visited);
        if (maxArea < area)
          maxArea = area;
      }
    }
  }

  return maxArea;
}

int main()
{
  vector<vector<int>> grid = {
      {1, 0, 0, 1, 0},
      {1, 0, 1, 0, 0},
      {0, 0, 1, 0, 1},
      {1, 0, 1, 1, 1},
      {1, 0, 1, 1, 0},
  };
  cout << maxAreaOfIsland(grid);
  return 0;
}