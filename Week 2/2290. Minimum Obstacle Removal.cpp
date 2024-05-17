class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), 1e9));
        dist[0][0] = 0;
        deque<vector<int>> dq;
        dq.push_back({0, 0, 0});

        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};

        while(!dq.empty()){
            int x = dq.front()[1];
            int y = dq.front()[2];
            int d = dq.front()[0];
            dq.pop_front();

            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                int cost = 0;
                if(nx < n and nx >= 0 and ny < m and ny >= 0){
                    if(grid[nx][ny] == 1){
                        cost = 1;
                    }
                    if(dist[nx][ny] > d + cost){
                        dist[nx][ny] = d + cost;
                        if(cost){
                            dq.push_back({dist[nx][ny], nx, ny});
                        }
                        else{
                            dq.push_front({dist[nx][ny], nx, ny});
                        }
                    }
                }
            }

        } 

        return dist[n-1][m-1];   
    }

};