//https://leetcode.com/submissions/detail/869527788/

class Solution {
public:
    int node;
    int mx = INT_MIN;
    vector<int>vis;
    vector<vector<int>>v;
    vector<int>ans,len;
    int dfs(int n){
        if(vis[n])return len[n];
        vis[n] = 1;
        int ans = 0;
        for(auto i:v[n]){
            ans = max(ans,dfs(i));
        }
        return len[n] = 1 + ans;
    }
    void traverse(int n){
        if(vis[n]) return;
        vis[n] = 1;
        ans.push_back(n);
        int mx = INT_MIN;
        int node = -1;
        for(auto i:v[n]){
            if(len[i]>mx){
                mx = len[i];
                node = i;
            }
        }
        if(node != -1){
            traverse(node);
        }
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        v.resize(n);
        vis.resize(n);
        len.resize(n);
        for(int i=0;i<n;i++) len[i]=0;
        for(int i=0;i<n;i++) vis[i] = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j] % nums[i] == 0){
                    v[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            int temp = dfs(i);
            if(temp > mx){
                mx = temp;
                node = i;
            }
        }
        for(int i=0;i<n;i++) vis[i] = 0;
        traverse(node);
        for(int i=0;i<ans.size();i++){
            ans[i]=nums[ans[i]];
        }
        return ans;
    }
};
