#include <bits/stdc++.h>
using namespace std;

class Graph
{
  int V;
  list<int> *l;

public:
  Graph(int v)
  {
    V = v;
    l = new list<int>[V + 1];
  }

  void addEdge(int i, int j, bool undir = true)
  {
    l[i].push_back(j);
    if (undir)
    {
      l[j].push_back(i);
    }
  }

  int minCostBFS(int source, int target)
  {
    queue<int> q;
    bool *visited = new bool[V]{0};
    int *dist = new int[V]{0};

    q.push(source);
    visited[source] = true;
    dist[source] = 0;

    while (!q.empty())
    {
      int f = q.front();
      q.pop();

      for (auto nbr : l[f])
      {
        if (!visited[nbr])
        {
          q.push(nbr);
          visited[nbr] = true;
          dist[nbr] = dist[f];
        }
      }
    }

    return dist[target];
  }
};

int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders)
{
  vector<int> board(n + 1, 0);
  // Jump for ladders
  for (auto x : ladders)
  {
    int s = x.first;
    int e = x.second;
    board[s] = e - s;
  }
  // Jump for snakes
  for (auto x : snakes)
  {
    int s = x.first;
    int e = x.second;
    board[s] = e - s;
  }

  // Graph
  Graph g(n + 1);
  for (int u = 1; u < n; u++)
  {
    for (int dice = 1; dice <= 6; dice++)
    {
      int v = u + dice;
      v += board[v];
      if (v <= n)
      {
        g.addEdge(u, v);
      }
    }
  }

  return g.minCostBFS(1, n);
}

int main()
{
  int n = 36;
  vector<pair<int, int>> ladders = {{2, 15}, {5, 7}, {9, 27}, {18, 29}, {25, 35}};
  vector<pair<int, int>> snakes = {{17, 4}, {20, 6}, {34, 12}, {24, 16}, {32, 30}};

  cout << min_dice_throws(n, snakes, ladders) << endl;

  return 0;
}