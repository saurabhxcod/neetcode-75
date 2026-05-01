class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int nei:adj[node]){
                if(!visited[nei]){
                    visited[nei]=true;
                    q.push(nei);
                }
            }
        }
        return count==n;
    }
};
