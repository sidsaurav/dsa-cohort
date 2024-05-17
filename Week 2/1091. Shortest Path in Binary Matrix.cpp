class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size()));
        queue<vector<int>> q;
        vis[0][0] = 1;
        if(grid[0][0] == 0) q.push({0, 0, 0});

        int dx[8] = {1,1,0,-1,-1,-1,0,1};
        int dy[8] = {0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int dist = q.front()[2];
            q.pop();

            if(x == grid.size()-1 and y == grid[0].size()-1){
               return dist + 1;
            }

            for(int i = 0; i<8; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx>=0 and nx<grid.size() and ny>=0 and ny<grid[0].size() and vis[nx][ny] == 0 and grid[nx][ny] == 0){
                    q.push({nx, ny, dist+1});
                    vis[nx][ny] = 1;
                }
            }
        }

        return -1;
    }
};