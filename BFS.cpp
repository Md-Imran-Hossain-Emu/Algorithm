

#include<bits/stdc++.h>
using namespace std;

#define White 1;
#define Gray 2;
#define Black 3;

int adj[100][100];
int color[100];

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int x;
        x=q.front();
        q.pop();
        cout << x<< "  ";

        for(int i=0;i<node;i++){
            if(adj[x][i]==1){
                q.push(i);
            }
            //bfs(i);
        }
    }
}

int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int nodes,edges;
    int n1,n2;
    cin>>nodes>>edges;
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cin >>n1>>n2;
        }
    }
    for(int i=0;i<nodes;i++){
        //if(!adj[][])
            bfs(i);
    }
}

