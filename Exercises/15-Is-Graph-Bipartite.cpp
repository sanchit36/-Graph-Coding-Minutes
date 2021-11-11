#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &graph, int node, vector<int> &color)
{
  if (color[node] == 0)
  {
    color[node] = 1;
  }

  for (auto nbr : graph[node])
  {
    if (color[nbr] == 0)
    {
      color[nbr] = 3 - color[node];
      if (!dfs(graph, nbr, color))
        return false;
    }
    else if (color[nbr] == color[node])
    {
      return false;
    }
  }
  return true;
}

bool isBipartite(vector<vector<int>> graph)
{
  int n = graph.size();
  vector<int> color(n, 0);

  for (int i = 0; i < n; i++)
  {
    if (color[i] == 0 && !dfs(graph, i, color))
    {
      return false;
    }
  }

  return true;
}
