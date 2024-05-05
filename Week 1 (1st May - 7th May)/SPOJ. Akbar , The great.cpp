// Question - https://www.spoj.com/problems/AKBAR/

#include <bits/stdc++.h>
using namespace std;



void run(){
    vector<vector<int>> adj;
    vector<bool> vis;
    int n, r, m;
    cin >> n >> r >> m;
    // cout << n << r << m;
    adj.resize(n+1, vector<int>());
    vis.resize(n+1, false);
    for(int i = 0; i<r; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pair<int, int>> q;

    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        q.push({a, b});
        vis[a] = true;
    }
    while(!q.empty()){
        auto node = q.front().first;
        auto st = q.front().second;
        q.pop();
        if(st == 0){
            continue;
        }
        for(auto &nbr: adj[node]){
            if(vis[nbr]==false){
                vis[nbr] = true;
                q.push({nbr, st-1});
            }
        }
    }

    for(int i = 1; i<=n; i++){
        if(vis[i] == false){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main(){
  int t; cin >> t;
  while(t--){
      run();
  }
}