class Solution {
public:
    vector<int>path;
    void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&v){
        if(!path.empty())return;
        vis[node]=1;
        v.push_back(node);
        if(node==0){
            path=v;
            v.pop_back();
            return;
        }
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,v);
            }
        }
        v.pop_back();
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<int>adj[n];
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>steps(n,INT_MAX);
        vector<int>v;
        vector<int>vis(n,0);
        dfs(bob,adj,vis,v);
        for(int i=0;i<path.size();i++){
            steps[path[i]]=i;
        }
        vector<int>step(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({-amount[0],0});
        for(int i=0;i<n;i++)vis[i]=0;
        vis[0]=1;
        step[0]=0;
        int ans=INT_MAX;
        while(!q.empty()){
            int node=q.top().second;
            int d=q.top().first;
            q.pop();
            int cnt=0;
            for(auto it:adj[node]){
                if(!vis[it]){
                    cnt++;
                    step[it]=step[node]+1;
                    vis[it]=1;
                    int d1=d;
                    if(steps[it]<step[it]){
                        d1+=0;
                    }
                    else if(steps[it]==step[it]){
                        d1+=(-(amount[it]/2));
                    }
                    else{
                        d1+=-amount[it];
                    }
                    q.push({d1,it});
                }
            }
            if(cnt==0){
                ans=min(ans,d);
            }
        }
        return -ans;
    }
};
