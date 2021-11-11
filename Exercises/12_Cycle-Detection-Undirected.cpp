#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<bool> &visited, vector<vector<int>> &v)
{
  visited[node] = true;
  for (auto nbr : v[node])
  {
    if (!visited[nbr])
    {
      bool nbrFoundACycle = dfs(nbr, node, visited, v);
      if (nbrFoundACycle)
        return true;
    }
    else if (nbr != parent)
    {
      return true;
    }
  }
  return false;
}

bool solve(int n, vector<vector<int>> edges)
{
  // genrating graph
  vector<vector<int>> v(n + 1);
  for (int i = 0; i < edges.size(); i++)
  {
    int x = edges[i][0], y = edges[i][1];
    v[x].push_back(y);
    v[y].push_back(x);
  }

  bool flag = false;
  vector<bool> visited(n + 1, false);
  for (int i = 1; i <= n; i++)
  {
    if (visited[i] == false)
    {
      flag = dfs(i, 0, visited, v);
    }
    if (flag == true)
      return true;
  }

  return false;
}