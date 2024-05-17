class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> g(n+1);
        for(auto &x : flights){
            g[x[0]].push_back({x[1], x[2]});
        }
        vector<int> dist(n+1, 1e9);
        dist[src] = 0;
        set<vector<int>> st;
        st.insert({0, 0, src}); // stops, dist, node -> our first priority is number of stops

        while(!st.empty()){
            auto fr = *st.begin();
            int d = fr[1];
            int node = fr[2];
            int stops = fr[0];
            st.erase(st.begin());

            for(auto &x : g[node]){
                if(dist[x.first] > d + x.second and stops <= k){
                    dist[x.first] = d + x.second;
                    st.insert({stops+1, dist[x.first], x.first});
                }
            }
        }

        if(dist[dst] == 1e9){
            return -1;
        }
        else{
            return dist[dst];
        }
    }
};