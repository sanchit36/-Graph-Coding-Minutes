#include <bits/stdc++.h>
using namespace std;

int stackSize(vector<bool> stack)
{
  int count = 0;
  for (auto x : stack)
  {
    if (x)
      count++;
  }
  return count;
}

bool dfs(int node, int parent, vector<vector<int>> &g, vector<bool> &visited, vector<bool> &stack)
{
  visited[node] = true;
  stack[node] = true;

  for (auto nbr : g[node])
  {
    if (!visited[nbr])
    {
      int subprob = dfs(nbr, node, g, visited, stack);
      if (subprob == true)
        return true;
    }
    else if (nbr != parent)
    {
      int size = stackSize(stack);
      if (size % 2 == 1 and size != 1)
        return true;
    }
  }

  stack[node] = false;
  return false;
}

bool solveBfs(vector<vector<int>> graph)
{
  int n = graph.size();
  vector<int> color(n, -1);

  for (int i = 0; i < n; i++)
  {
    if (color[i] == -1)
    {
      queue<int> q;
      q.push(i);
      color[i] = 0;

      while (!q.empty())
      {
        int f = q.front();
        q.pop();

        for (auto itr : graph[f])
        {
          if (color[itr] == -1)
          {
            color[itr] = color[i] ^ 1;
            q.push(itr);
          }
          else if (color[itr] == color[f])
          {
            return true;
          }
        }
      }
    }
  }
  return false;
}

bool solve(vector<vector<int>> graph)
{
  int n = graph.size();
  vector<bool> visited(n, false);
  vector<bool> stack(n, false);

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      bool ans = dfs(i, -1, graph, visited, stack);
      if (ans == true)
        return true;
    }
  }

  return false;
}

int main()
{
  vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  cout << solveBfs(graph) << endl;
  return 0;
}