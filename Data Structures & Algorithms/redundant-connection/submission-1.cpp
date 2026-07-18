class Solution {
public:
        int findroot(vector<int>&parent , int node){

            if(parent[node] == node ){
                return node;
            }

            return parent[node] = findroot(parent , parent[node]);
        }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int>parent(n+1);

        for(int i = 0 ; i<=n ; i++){
            parent[i] = i;
        }


        for(auto &edge : edges){
            int root1 = findroot(parent , edge[0]);
            int root2 = findroot(parent , edge[1]);

            if(root1 == root2){
                return edge;
            }
            else{
                parent[root1] = root2;
            }
        }

    }
};
