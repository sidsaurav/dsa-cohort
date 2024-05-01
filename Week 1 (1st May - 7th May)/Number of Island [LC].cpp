//https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:

    int dx[4] = {0,-1,0,1};
    int dy[4] = {1,0,-1,0};

    void dfs(int x, int y, vector<vector<bool>>& vis, vector<vector<char>>& grid){
        vis[x][y] = true;

        for(int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 and nx<vis.size() and ny>=0 and ny<vis[0].size() and vis[nx][ny] == false and grid[nx][ny] == '1'){
                dfs(nx, ny, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' and !vis[i][j]){
                    dfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};