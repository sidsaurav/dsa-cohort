// spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    vector<vector<int>> vis(9, vector<int>(9, 0));
    string str1, str2;
    cin >> str1 >> str2;

    queue<pair<int, int>> q;
    int i = (int)(str1[0] - 'a') + 1;
    int j = (int)(str1[1] - '0');
    q.push({i, j});
    vis[i][j] = true;

    pair<int, int> dest;
    i = (int)(str2[0] - 'a') + 1;
    j = (int)(str2[1] - '0');
    dest = {i, j};

    // cout << dest.first << " - " << dest.second << endl;
    int lev = 0;

    vector<int> dx = {1, 1, 2, 2, -1, -1, -2, -2};
    vector<int> dy = {2, -2, 1, -1, 2, -2, 1, -1};

    while (!q.empty())
    {
      int sz = q.size();
      lev++;
      for (int i = 0; i < sz; i++)
      {
        auto fr = q.front();
        q.pop();
        if (fr == dest)
          cout << lev - 1 << endl;
        for (int i = 0; i < 8; i++)
        {
          int nx = fr.first + dx[i];
          int ny = fr.second + dy[i];

          if (nx >= 1 and nx <= 8 and ny >= 1 and ny <= 8 and vis[nx][ny] == 0)
          {
            q.push({nx, ny});
            vis[nx][ny] = 1;
          }
        }
      }
    }
  }
}