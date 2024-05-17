class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n+1, vector<int>(m+1, 1e9));
        dist[0][0] = 0;
        deque<pair<int, int>> q;
        q.push_back({0, 0}); 

        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        
        while(!q.empty()){
            auto x = q.front().first;
            auto y = q.front().second;
            q.pop_front();

            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                int wt = 1;
                if(i == 0 and grid[x][y] == 1){
                    wt = 0;
                }

                if(i == 1 and grid[x][y] == 3){
                    wt = 0;
                }

                if(i == 2 and grid[x][y] == 2){
                    wt = 0;
                }

                if(i == 3 and grid[x][y] == 4){
                    wt = 0;
                }


                if(nx >= 0 and nx < n and ny >= 0 and ny < m and dist[nx][ny] > dist[x][y] + wt){
                    dist[nx][ny] = dist[x][y] + wt;
                    if(wt == 0){
                        q.push_front({nx, ny});
                    }
                    else{
                        q.push_back({nx, ny});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};