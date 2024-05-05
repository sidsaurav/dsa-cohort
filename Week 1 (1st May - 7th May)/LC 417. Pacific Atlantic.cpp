// https://leetcode.com/problems/pacific-atlantic-water-flow/
// we can use bfs as well as dfs here

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis1(n, vector<int>(m, 0));
        vector<vector<int>> vis2(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        for(int i = 0; i<n; i++){
            q.push({i, 0});
            vis1[i][0] = 1;
        }

        for(int j = 0; j<m; j++){
            q.push({0, j});
            vis1[0][j] = 1;
        }
        

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]>=grid[x][y] and vis1[nx][ny]==0){
                    q.push({nx, ny});
                    vis1[nx][ny] = 1;
                }
            }
        }

        
        

        for(int i = 0; i<n; i++){
            q.push({i, m-1});
            vis2[i][m-1] = 1;
        }

        for(int j = 0; j<m; j++){
            q.push({n-1, j});
            vis2[n-1][j] = 1;
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]>=grid[x][y] and vis2[nx][ny]==0){
                    q.push({nx, ny});
                    vis2[nx][ny] = 1;
                }
            }
        }
        // for(auto &x : vis2){
        //     for(auto &y : x){
        //         cout << y <<" ";
        //     }
        //     cout << endl;
        // }

        vector<vector<int>> ans;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis1[i][j] and vis2[i][j]) ans.push_back({i, j});
            }
        }


        return ans;
    }
};