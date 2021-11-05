#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList)
{
  unordered_set<string> s;
  for (auto itr : wordList)
  {
    s.insert(itr);
  }

  int ans = 0;
  queue<string> q;
  q.push(beginWord);

  while (!q.empty())
  {
    ans++;
    vector<string> v;
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
      string word = q.front();
      if (word == endWord)
      {
        return ans;
      }
      for (int j = 0; j < word.size(); j++)
      {
        char ch = word[j];
        for (int k = 0; k < 26; k++)
        {
          word[j] = char(97 + k);
          if (s.find(word) != s.end())
          {
            v.push_back(word);
            s.erase(word);
          }
        }
        word[j] = ch;
      }
      q.pop();
    }
    for (auto itr : v)
    {
      q.push(itr);
    }
  }

  return 0;
}

int main()
{

  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

  cout << ladderLength(beginWord, endWord, wordList) << endl;
  return 0;
}