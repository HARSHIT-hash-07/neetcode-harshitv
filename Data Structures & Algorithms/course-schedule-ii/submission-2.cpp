class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses , 0);
        int coursestaken = 0;


        vector<int>vis(numCourses + 1 , 0);

        for(auto &pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int>q;
        vector<int>order;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
                order.push_back(i);
            }
        }

        while(!q.empty()){
            int currcourse = q.front();
            q.pop();
            coursestaken++;

            for (int nextCourse : adj[currcourse]) {
                inDegree[nextCourse]--;
                
                // If it now has 0 prerequisites, we can take it!
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                    order.push_back(nextCourse);
                }
            }
        }

        if(coursestaken == numCourses){
            return order;
        }
        else{
            return {};
        }

        
    }
};
