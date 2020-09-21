VI tree[N]; // The bridge edge tree formed from the given graph
VI graph[N];int U[M],V[M];  //edge list representation of the graph. 
bool isbridge[M]; // if i'th edge is a bridge edge or not 
int visited[N];int arr[N],T; //supporting arrays
int cmpno;
queue<int> Q[N];
 
int adj(int u,int e){
    return U[e]==u?V[e]:U[e];
}
int dfs0(int u,int edge)    //marks all the bridges
{
    visited[u]=1;
    arr[u]=T++;
    int dbe = arr[u];
    for(int i=0;i<(int)graph[u].size();i++)
    {
        int e = graph[u][i];
        int w = adj(u,e);
        if(!visited[w])
            dbe = min(dbe,dfs0(w,e));
        else if(e!=edge)
            dbe = min(dbe,arr[w]);
    }
    if(dbe == arr[u] && edge!=-1)
        isbridge[edge]=true;
    return dbe;
}
 
void dfs1(int v) //Builds the tree with each edge a bridge from original graph
{
    int currcmp = cmpno;    // current component no.
    Q[currcmp].push(v);    // A different queue for each component, coz   during bfs we shall go to another component (step of dfs) and then come   back to this one and continue our bfs
    visited[v]=1;
    while(!Q[currcmp].empty())    //bfs. Exploring all nodes of this  component
    {
        int u = Q[currcmp].front();    
        Q[currcmp].pop();    
        for(int i=0;i<(int)graph[u].size();i++)
        {
            int e = graph[u][i];
            int w = adj(u,e);
            if(visited[w])continue;
            //if the edge under consideration is bridge and
            //other side is not yet explored, go there (step of dfs)
            if(isbridge[e])
            {
                cmpno++;
                tree[currcmp].push_back(cmpno);
                tree[cmpno].push_back(currcmp);
                dfs1(w);
            }
            else     //else continue with our bfs
            {
                Q[currcmp].push(w);
                visited[w]=1;
            }
        }
    }
}
