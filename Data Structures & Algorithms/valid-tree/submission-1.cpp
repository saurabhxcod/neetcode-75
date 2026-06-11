class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int>q;
        q.push(0);
        visited[0]=true;
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int neighbour:adj[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
        return count==n;
            
            
    }
};
