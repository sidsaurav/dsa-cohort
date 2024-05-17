class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> g(n);

        for(auto &x : roads){
            g[x[0]].push_back({x[1], x[2]});
            g[x[1]].push_back({x[0], x[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> cnt(n, 0);
        dist[0] = 0;
        cnt[0] = 1;
        
        set<pair<long long, long long>>s;
        s.insert({0, 0});

        while(!s.empty()){
            long long node = s.begin()->second;
            long long d = s.begin()->first;
            s.erase(s.begin());
            long long mod = 1e9+7;
            for(auto &x : g[node]){
                long long newNode = x.first;
                long long wt = x.second;

                if(dist[newNode] > d + wt){
                    dist[newNode] = d + wt;
                    s.insert({dist[newNode], newNode});
                    cnt[newNode] = cnt[node]%mod;
                }
                else if(dist[newNode] == d + wt) {
                    cnt[newNode] = (cnt[newNode]%mod + cnt[node]%mod)%mod;
                }
            }
        }
        return cnt[n-1];
    }
};