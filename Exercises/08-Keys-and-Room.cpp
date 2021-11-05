#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &rooms, bool *visited)
{
  visited[node] = true;
  for (int nbr : rooms[node])
  {
    if (!visited[nbr])
    {
      dfs(nbr, rooms, visited);
    }
  }
}

bool canVisitAllRooms(vector<vector<int>> rooms)
{
  int n = rooms.size();
  bool *visited = new bool[n]{0};
  dfs(0, rooms, visited);

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
      return false;
  }
  return true;
}

int main(int argc, char **argv)
{
  return 0;
}