class Solution {
public:
    typedef pair<int,int> pi;
    const int inf=1e9;
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dist(n+1,inf);
        dist[0]=0;
        unordered_map<int,vector<pi>>adj;
        for(int i=0;i<=n;i++){
            if(i+1<=n){
                adj[i].push_back({i+1,costs[i]+1});
            }
            if(i+2<=n){
                adj[i].push_back({i+2,costs[i+1]+4});
            }
            if(i+3<=n){
                adj[i].push_back({i+3,costs[i+2]+9});
            }
        }
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        int src=0;
        int dest=n;
        pq.push({0,src});
        while(!pq.empty()){
            auto [currDist,node]=pq.top();
            pq.pop();
            if(currDist>dist[node]) continue;
            for(auto p:adj[node]){
                int neigh=p.first;
                int wt=p.second;
                if(dist[neigh]>wt+currDist){
                    dist[neigh]=wt+currDist;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        return dist.back();
    }
};
