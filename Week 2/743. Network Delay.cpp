class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n+1);

        for(auto &x : times){
            g[x[0]].push_back({x[1], x[2]});
        }

        vector<int> dist(n+1, 2e9);

        multiset<pair<int, int>> ms;
        dist[k] = 0;
        ms.insert({0, k});

        while(!ms.empty()){
            auto fr = *ms.begin();
            ms.erase(ms.begin());
            int d = fr.first;
            int node = fr.second;

            for(auto &x : g[node]){
                if(dist[x.first] > d + x.second){
                    dist[x.first] = d + x.second;
                    ms.insert({dist[x.first], x.first});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i<=n; i++){
            ans = max(ans, dist[i]);
        }

        if(ans == 2e9){
            return -1;
        }
        return ans;
    }
};