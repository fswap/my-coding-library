#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

struct DSU
{
    int N;
    vector<int> parent,sz;
    DSU(int n)
    {
        N=n;
        parent.resize(n);
        sz.resize(n);
        for(int i=0;i<N;i++)
        {
            parent[i]=i;
            sz[i]=1;
        }
    }
    int find(int a)
    {
        if(a==parent[a])
            return a;
        return parent[a]=find(parent[a]);
    }
    int merge(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a!=b)
        {
            if(sz[a]<sz[b])
                swap(a,b);
            parent[b]=a;
            sz[a]+=sz[b];
        }
    }
};

int kruskals(int n,vector<pair<int,pii>> edges)
{
    int sum=0;
    DSU st(n);
    sort(edges.begin(),edges.end());
    for(auto e:edges)
    {
        int w=e.first;
        int u=e.second.first;
        int v=e.second.second;
        int ru=st.find(u);
        int rv=st.find(v);
        if(ru!=rv)
        {
            sum+=w;
            st.merge(ru,rv);
        }
    }
    return sum;
}

int helper(int n,int m)
{
    vector<pair<int,pii>> edges;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;x--;y--; // edges shud be 0 based
        edges.push_back({w,{x,y}});
    }
    return kruskals(n,edges);
}

void solve()
{
    int i,n,k;
    cin>>n>>k;
    vector<int> camps(n);
    vector<int> aisles(n);
    for(i=0;i<n;i++)
    cin>>camps[i]>>aisles[i];
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(i=0;i<n;i++)
    {
        int ans=helper(camps[i],aisles[i]);
        pq.push({ans,i+1});
        if(pq.size()>k)
        pq.pop();
    }
    cout<<pq.top().second<<" "<<pq.top().first<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    //cin>>t;
    while(t--)
        solve();
}

/*

#include <bits/stdc++.h>
using namespace std;
struct edge{
    int a;
    int b;
    int w;
};
bool comp(edge a, edge b){
    return a.w < b.w;
}
int find(int a, int par[]){
    if(par[a]==-1) return a;
    return par[a] = find(par[a], par);
}
void merge(int a, int b, int par[]){
    par[a] = b;
}
int solve(int n, int m){
    edge arr[m];
    int par[n+1];
    for(int i=0;i<=n;i++) par[i]=-1;
    for(int i=0;i<m;i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].w;
    }
    sort(arr, arr+m, comp);
    int sum =0;
    for(int i=0;i<m;i++){
        int u = find(arr[i].a, par);
        int v = find(arr[i].b, par);
        if(u!=v){
            sum +=arr[i].w;
            merge(u,v, par);
        }
        else{
            continue;
        }
    }
    return sum;
}
int main(){
    int n,k; cin >> n >> k;
    vector<int> camps(n);
    vector<int> aisles(n);
    for(int i=0;i<n;i++){
        int a,c; cin >> a >> c;
        camps[i] = a;
        aisles[i] = c;
    }
    vector<int> res;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    for(int i=0;i<n;i++){
        int ans = solve(camps[i],aisles[i]);
        pq.push({ans,i+1});
        if(pq.size()>k)
            pq.pop();
    }
        cout << pq.top().second <<" " << pq.top().first << endl;
}

Input format
2 1
4 4
4 3
1 2 10
1 3 15
2 4 5
3 4 20
1 2 10
1 3 5
1 4 20

2 2
3 2
4 4
1 2 10
1 3 5
1 2 10
1 3 15
2 4 5
3 4 20


*/