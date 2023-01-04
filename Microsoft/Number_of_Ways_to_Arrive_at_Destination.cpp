class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int dest = n - 1;
        int mod = 1e9 + 7;
       
        vector<pair<int, int>> adj[n];
        for (auto x : roads)
            {
                adj[x[0]].push_back({x[1], x[2]});
                adj[x[1]].push_back({x[0], x[2]});
            }
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
        pq.push({0, 0});
        vector<long long> dist(n, 1e18);
        dist[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long node_distance = it.first;
            int node = it.second;
            for (auto x : adj[node])
            {
                int adjnode = x.first;
                long edgewt = x.second;
                if (dist[adjnode] > edgewt + node_distance)
                {
                    ways[adjnode] = ways[node];
                    dist[adjnode] = edgewt + node_distance;
                    pq.push({dist[adjnode], adjnode});
                }
                else if (dist[adjnode] == edgewt + node_distance)
                {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[dest];   
        }
};