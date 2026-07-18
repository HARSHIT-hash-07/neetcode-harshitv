class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int , int>>>adj(n+1);

        for(auto &v : times){
            adj[v[0]].push_back({v[1] , v[2]});
        }

        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int, int>>>pq;

        pq.push({0,k}); //{distance , node};

        while(!pq.empty()){

            int currdist = pq.top().first;
            int currnode = pq.top().second;

            pq.pop();

            if(currdist > dist[currnode]) continue ; //no use then



            for(auto &edge : adj[currnode]){
                int ngh = edge.first;
                int weight = edge.second;

                if(currdist + weight < dist[ngh]){
                    dist[ngh] = currdist + weight;
                    pq.push({dist[ngh] , ngh});
                }
            }

        }


        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1; // Node i was unreachable
            }
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
        
    }
};
