//https://leetcode.com/submissions/detail/869076996/
//not beautiful code, explanations to be added later

class Solution {
public:
int b;
int height = 0;
vector<vector<int>>v;
vector<int>val;
map<int,int>vis;
map<int,int>price;
    bool dfs(int n,int h){
        vis[n] = 1;
        bool res = 0;
        if(n == b){
            res = true;
        }
        for(auto i:v[n]){
            if(!vis[i])
                res |= dfs(i,h+1);
        }
        if(res){
            if(height % 2 == 0){
                if(h==(height/2)){
                    val[n]/=2;
                }
                if(h>(height/2)){
                    val[n]=0;
                }
            }else{
                if(h>=((height+1)/2)){
                    val[n]=0;
                }
            }
        }
        return res;
    }
    void dfs2(int n){
        if(vis[n])return;
        vis[n]=1;
        bool gone = 0;
        for(auto i:v[n]){
            if(!vis[i]){
                dfs2(i);
                gone = 1;
            }
        }
        if(!gone){
            mx=max(mx,price[n]);
        }
    }
    int mx = INT_MIN;
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        v.resize(n);
        b = bob;
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        queue<int>q;
        q.push(0);
        map<int,int>level;
        level[0]=0;
        while(!q.empty()){
            int top = q.front();
            vis[top]=1;
            q.pop();
            for(auto i:v[top]){
                if(!vis[i]){
                    q.push(i);
                    level[i]=level[top]+1;
                }
            }
        }
        vis.clear();
        height = level[bob];
        for(auto i:amount){
            val.push_back(i);
        }
        dfs(0,0);
        vis.clear();
        while(q.size())q.pop();
        q.push(0);        
        for(int i=0;i<val.size();i++){
            price[i]=val[i];
        }
        map<int,int>par;
        while(!q.empty()){
            int top = q.front();
            vis[top]=1;
            q.pop();
            for(auto i:v[top]){
                par[i]=top;
                if(!vis[i]){
                    q.push(i);
                    price[i]+=price[top];   
                }                
            }
        }
        vis.clear();
        dfs2(0);
        return mx;
    }
};
