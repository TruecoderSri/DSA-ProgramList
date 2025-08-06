
class Solution {
  public:
  
  
//   In this algo we check for cycle in the graph and if isn't then we consider it a safe node 
  
    bool dfs(int i,vector<int>adj[],vector<int>&check,vector<int>&vis,vector<int>&path_vis){
        vis[i]=1;
        path_vis[i]=1;
        check[i]=0;
        for (auto it:adj[i]){
            if(!vis[it]){
             if(dfs(it,adj,check,vis,path_vis)){
                check[i]=0;
                return true;
             }
            }
            else if(path_vis[it]){
                check[i]=0;
                return true;
            }
        }
        check[i]=1;
        path_vis[i]=0;
        
        return false;
        
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<int> ans;
        vector<int> vis(V,0);
        vector<int> path_vis(V,0);
        vector<int> check (V,0); // to mark all nodes which are safe
        for(int i=0;i<V;i++){
            if(!vis[i])
            dfs(i,adj,check,vis,path_vis);
           
        }
        
        for(int i=0;i<V;i++)
         if(check[i]==1) 
          ans.push_back(i);
    
        return ans;
    }
    
};