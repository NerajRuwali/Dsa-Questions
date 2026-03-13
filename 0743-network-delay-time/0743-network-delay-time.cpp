class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // first we decalare the adjacency list 
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0],v=times[i][1],wt=times[i][2];
            adj[u].push_back({v,wt});

        }
        //decalare priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq; //{dist,node}
        vector<int>dist(n+1,INT_MAX);
        dist[0]=-1;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it=pq.top();
            int dis=it.first;
            int node=it.second;
            pq.pop();
            for(auto it:adj[node]){
                int nodeval=it.first;
                int cost=it.second;
                if(cost+dis<dist[nodeval]){
                    dist[nodeval]=cost+dis;
                    pq.push({cost+dis,nodeval});
                }
            }
        }
        int ans=*max_element(dist.begin(),dist.end());
        return ans==INT_MAX?-1:ans;
    }
};