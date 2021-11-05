#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, vector<int>> &g, bool *visited, int *area)
{
  visited[node] = true;
  for (auto nbr : g[node])
  {
    if (!visited[nbr])
    {
      *area = *area + 1;
      dfs(nbr, g, visited, area);
    }
  }
}

int maxAreaOfIsland(vector<vector<int>> grid)
{
  int c = 0;
  int n = grid.size(), m = grid[0].size();
  int maxArea = 0;
  vector<vector<int>> board(n);

  // Initializing the board
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      board[i].push_back(c);
      c++;
    }
  }

  // Graph construction
  unordered_map<int, vector<int>> g;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] != 0)
      {
        int x = board[i][j];
        g[x] = {};
        // left
        if (j - 1 >= 0 && grid[i][j - 1] != 0)
        {
          g[x].push_back(board[i][j - 1]);
        }
        // right
        if (j + 1 < m && grid[i][j + 1] != 0)
        {
          g[x].push_back(board[i][j + 1]);
        }
        // up
        if (i - 1 >= 0 && grid[i - 1][j] != 0)
        {
          g[x].push_back(board[i - 1][j]);
        }
        // down
        if (i + 1 < n && grid[i + 1][j] != 0)
        {
          g[x].push_back(board[i + 1][j]);
        }
      }
    }
  }

  bool *visited = new bool[n * m]{0};
  for (auto i : g)
  {
    if (!visited[i.first])
    {
      int area = 1;
      dfs(i.first, g, visited, &area);
      if (maxArea < area)
        maxArea = area;
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