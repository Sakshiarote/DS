#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of cities: ";
    cin>>n;

    int g[10][10];
    cout<<"Enter adjacency matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>g[i][j];

    // DFS to check connected
    bool vis[10]={0};
    int st[10], top=-1;
    st[++top]=0; vis[0]=1;

    while(top!=-1){
        int u=st[top--];
        for(int v=0;v<n;v++)
            if(g[u][v] && !vis[v]){
                vis[v]=1;
                st[++top]=v;
            }
    }

    bool connected=true;
    for(int i=0;i<n;i++)
        if(!vis[i]) connected=false;

    if(connected) cout<<"Graph is Connected";
    else cout<<"Not Connected";
}