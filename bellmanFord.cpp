#include<bits/stdc++.h>
using namespace std ;

const int inf =999;
int main(){
    int n,m;
    cout<<"enter size "<<endl;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int source;
    cout<<"enter source"<<endl;
    cin>>source;
    vector<int> dist(n,inf);
    dist[source]=0;
    for(int i=0;i<n-1;i++){
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            dist[v]=min(dist[v],w+dist[u]);
        }
    }
    for(auto i:dist){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;

}
/*
5 8
1 2 3
3 2 5
1 3 2
3 1 1
1 4 2
0 2 4
4 3 -3
0 1 -1
0
*/