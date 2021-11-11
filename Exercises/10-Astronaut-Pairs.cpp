#include <bits/stdc++.h>
using namespace std;

int dfs(int node, unordered_map<int, vector<int>> &g, bool *visited)
{
  visited[node] = true;
  int size = 1;
  for (int nbr : g[node])
  {
    if (!visited[nbr])
    {
      size += dfs(nbr, g, visited);
    }
  }
  return size;
}

int count_pairs(int N, vector<pair<int, int>> astronauts)
{
  // Graph
  unordered_map<int, vector<int>> g;
  for (auto x : astronauts)
  {
    g[x.first].push_back(x.second);
    g[x.second].push_back(x.first);
  }

  // Calculations
  bool *visited = new bool[N]{0};
  int ans = N * (N - 1) / 2;
  for (auto x : g)
  {
    if (!visited[x.first])
    {
      int csize = dfs(x.first, g, visited);
      ans -= csize * (csize - 1) / 2;
    }
  }

  return ans;
}

int main()
{
  int n = 5;
  vector<pair<int, int>> a = {{0, 1}, {2, 3}, {0, 4}};
  cout << count_pairs(n, a);
  return 0;
}