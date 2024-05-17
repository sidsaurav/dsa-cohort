class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> g(n);

        for(auto &x : edges){
            g[x[0]].push_back({x[1], x[2]+1});
            g[x[1]].push_back({x[0], x[2]+1});
        }

        vector<int> dist(n, 1e9);
        dist[0] = 0;
        set<pair<int, int>> s;
        s.insert({0, 0});

        while(!s.empty()){
            auto d = s.begin() -> first;
            auto node = s.begin() -> second;

            s.erase(s.begin());

            for(auto &x : g[node]){
                if(dist[x.first] > d + x.second){
                    dist[x.first] = d + x.second;
                    s.insert({dist[x.first], x.first});
                }
            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            if(dist[i] <= maxMoves) ans++;
        }

        for(auto &x : edges){
            int a = x[0], b = x[1], newNodes = x[2];
            int remA = max(maxMoves - dist[a], 0);
            int remB = max(maxMoves - dist[b], 0);
            if(remA + remB >= newNodes){
                ans += newNodes;
            }
            else{
                ans += remA + remB;
            }
        }

        return ans;
    }
};