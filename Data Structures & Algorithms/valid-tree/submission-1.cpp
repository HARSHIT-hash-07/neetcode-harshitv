class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1) {
            return false; 
        }

        vector<int>vis(n);
        vis[0] = 1;
        queue<pair<int,int>>q; //  node , par
        vector<vector<int>>adj(n , vector<int>());


        for(auto pair : edges){
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }

        q.push({0,-1});

        while(!q.empty()){

            int par = q.front().second;
            int node = q.front().first;
            q.pop();

            for(auto it : adj[node]){
                if(vis[it] != 1){
                    q.push({it , node});
                }
                else{
                    if(it == par){
                        continue;
                    }
                    else{
                        return false;
                    }
                }

                vis[it] = 1;
            }

        }


        for(int i = 0; i < n; i++) {
    if(vis[i] == 0) {
        return false; // We missed a node! It's disconnected!
    }
}


        return true;


    }
};
